#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
void objects()

  {
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  //zu bearbeitende Dateien eingeben
  vector<string> objects;
     objects.push_back("r1");// freq.push_back(50.0);
      objects.push_back("r2");
      objects.push_back("r3");
      objects.push_back("r4");
      objects.push_back("r5");
     string rest_of_filename("_HM1508-2.csv");

  
  //Deklarieren
  ifstream in;   //Input Stream Reader
  TCanvas *c1;
  int o;
  string buffer;

  
  //Initialisieren für object o, Duchlaufparameter für die files
  o=0;
  
  float t_0 = 0;
  float d_t = 7.3;
  while(o<objects.size())
    {
    c1=new TCanvas("c1","Hier den Titel hin",2003,200,700,500);
    //Oeffnen der Datei
    string filename = objects[o]+rest_of_filename;
    TGraph *graph=new TGraph(filename.c_str(),"%lg,%lg");
    c1->Divide(2,1);
    c1->cd(1);

    //histo->Draw();
    graph->SetLineColor(29);
    graph->GetXaxis()->SetTitle("time t");
    graph->GetXaxis()->SetRangeUser(t_0, t_0+d_t);
    graph->GetYaxis()->SetTitle("U/mV");
    graph->Draw("ALP");
    
    //histo->Fit("f1");
    //c1->cd(2);
    //f1->Draw("SAME");
    //transform the coordinates to polar!!

    double ybar=0;
    double buffer2;

    cout<<(graph->GetY())[45]<<endl;
    cout<<graph->GetN()<<endl;

    for(int i=0;i<graph->GetN();i++)
      {
        buffer2=ybar+(graph->GetY())[i];
        ybar=buffer2;
      }
    ybar=ybar/(graph->GetN());
    cout<<"ybar= "<<ybar<<endl;

    //cout<<"Vor der Schleife"<<endl;

    vector<double> r;
    int length=290;//graph->GetN();
    cout<<"habe r definiert successfull!"<<endl;
    for(int b=0;b<length;b++)
    {
      cout<<"in loop"<<endl;
      r.push_back(fabs((graph->GetY())[b]-ybar));    //fabs is abs for doubles
    }
    cout<<"groesse von r"<<r.size()<<endl;
    const int anzahl=r.size();
    Double_t rv[anzahl];
    for(int j=0;j<anzahl;j++)
    { 
      rv[j]=r[j];
    }
   
    //TCanvas *CPol=new TCanvas("CPol","TGraphPolar Examples",600,600);
    c1->cd(2);
   
    TGraphPolar *grP=new TGraphPolar(anzahl,graph->GetX(),rv);   //first is angle, second is radius
 
    
    //grP->GetPolargram()->SetToRadian();
    //c1_2->Range(-.25,-.25,.25,.25);
    grP->Draw("AL");
    
    c1->Update();
    c1->Print((objects[o]+".png").c_str());
    o++;
    }
  return;
  }
