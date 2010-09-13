#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

void sin_fit3()

  {
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptFit(1111);
  //zu bearbeitende Dateien eingeben
  vector<string> files; vector<double> freq;

//   files.push_back("_HM1508-2.csv");
     files.push_back("r1"); freq.push_back(50.0);
     files.push_back("r2"); freq.push_back(50.0);
     files.push_back("r3"); freq.push_back(50.0);
     files.push_back("r4"); freq.push_back(50.0);
     files.push_back("r5"); freq.push_back(50.0);
     
     string rest_of_filename("_HM1508-2.csv");


//      files.push_back("r01_02_296s_HM1508-2.csv");
  

  //datei für ausgabe
  ofstream outfile("sin_fit.tex");
  //standard tex header
  outfile<<"\\begin{tabular}{ccccc}"<<endl;
  outfile<<"\\topline"<<endl;
  outfile<<"Datei & $\\chi^2 / ndf$ & Offset $a$ [V] & Amplitude $b$ [V] & Phase $d$\\"<<endl;
  outfile<<"\\midline"<<endl;

  //Declaration, neede Variables
  TCanvas *c1;
  string resistor;
  int times_turned_per_m;
  double time;
  int f;
  string buffer;

  
  //Initialisieren für file f, Duchlaufparameter für die files
  f=0;
  //später gewünschte ausgabe
  vector<double> chi2;
  vector<double> a;
  vector<double> b;
  vector<double> c;
  vector<double> d;
  vector<double> ae;
  vector<double> be;
  vector<double> ce;
  vector<double> de;
    
  while(f<files.size())
    {
    resistor=files[f];
    
    //some simple output
    cout<<resistor<<endl;

  
    string fit_title("Fit ");
    fit_title += resistor;
  
    //create TCanvas
    c1=new TCanvas("c1",fit_title.c_str(),2003,200,700,500);

    string filename = files[f] + rest_of_filename;
    
    //load data out of file
    TGraph *graph=new TGraph(filename.c_str(),"%lg,%lg");
    //get max x value for fit boundary
    double xmax=graph->GetXaxis()->GetXmax();

    //define fit function for individual graph
    TF1 *f1 = new TF1("f1","[0]+[1]*sin(pi/180*[2]*x+[3])",0,xmax);
  

    //optimize fit func for spezified file
    
    f1->SetParameter(0,-0.6);
    f1->SetParameter(1, 0.6);
    f1->SetParameter(2, freq[f]);
    f1->SetParameter(3, 0);
      
    graph->Draw("ALP");
    graph->SetLineColor(29);
    graph->GetXaxis()->SetTitle("time t");
    graph->GetYaxis()->SetTitle("U/mV");
    
    //fitting the graph
    graph->Fit("f1");
     
    //Printing the graph as picture
    buffer=files[f]+".eps";
    c1->Print(buffer.c_str());

    //read out the fit values
    chi2.push_back(f1->GetChisquare());
    a.push_back(f1->GetParameter(0));
    b.push_back(f1->GetParameter(1));
    c.push_back(f1->GetParameter(2));
    d.push_back(f1->GetParameter(3));
    ae.push_back(f1->GetParError(0));
    be.push_back(f1->GetParError(1));
    ce.push_back(f1->GetParError(2));
    de.push_back(f1->GetParError(3));


    //write this values to the tex file outfile
    outfile<<"\\texttt{"+files[f]<<"} & "<<chi2[f]<<" & "<<a[f]<<"$\\pm$"<<ae[f]<<" & "<<b[f]<<"$\\pm$"<<be[f]<<" & "<<c[f]<<"$\\pm$"
	   <<ce[f]<<"\\\\"<<endl;  
    f++;
    }
  return;
  }
