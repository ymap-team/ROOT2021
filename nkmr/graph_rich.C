{
  gStyle->SetOptStat(0);
  TCanvas *c = new TCanvas("canvas","hoge",500,700);
  c->SetLogy(1);
  c->SetMargin(0.15,0.1,0.2,0.1);//lrbt

  TH1D *waku = new TH1D("waku","fermion mass;;MeV/c^{2}",6,0,6);
  waku->SetMinimum(1e-7);
  waku->SetMaximum(1e10);
  TString label[6]={"","1st gen.","2nd gen.","3rd gen.","",""};
  for(int i=0; i<6; i++) waku->GetXaxis()->SetBinLabel(1+i,label[i]);
  waku->GetXaxis()->SetLabelSize(0.06);
  waku->GetXaxis()->LabelsOption("v");
  waku->GetXaxis()->SetTickLength(0);
  waku->GetXaxis()->SetNdivisions(505);
  waku->Draw();

  TGraph *g[4];
  for(int i=0; i<4; i++) g[i] = new TGraph();
  g[0]->SetPoint(0, 1.5, 0.511);
  g[0]->SetPoint(1, 2.5, 106);
  g[0]->SetPoint(2, 3.5, 1777);
  g[1]->SetPoint(0, 1.5, 2.16);
  g[1]->SetPoint(1, 2.5, 1.27e3);
  g[1]->SetPoint(2, 3.5, 172.76e3);
  g[2]->SetPoint(0, 1.5, 4.67);
  g[2]->SetPoint(1, 2.5, 93);
  g[2]->SetPoint(2, 3.5, 4.18e3);

  int color[4] = {2,3,4,6}, style[4] = {8, 22, 23, 4};
  for(int i=0; i<4; i++){
    g[i]->SetMarkerColor(color[i]);
    g[i]->SetMarkerStyle(style[i]);
    g[i]->SetLineColor(color[i]);
    g[i]->SetLineStyle(2);
    if(i<3) g[i]->Draw("samePL");
  }

  TLegend *leg = new TLegend(0.5,0.35,0.8,0.5);
  leg->AddEntry(g[1],"quark(u-type)","P");
  leg->AddEntry(g[2],"quark(d-type)","P");
  leg->AddEntry(g[0],"lepton","P");
  leg->AddEntry(g[3],"neutrino","P");
  leg->SetFillColor(0);
  leg->Draw();

  TLatex *latex[9];
  latex[0] = new TLatex(1.5+0.2,    0.511,"e");
  latex[1] = new TLatex(2.5+0.2,      106,"#mu");
  latex[2] = new TLatex(3.5+0.2, 0.5*1777,"#tau");
  latex[3] = new TLatex(1.5+0.2,     2.16,"u");
  latex[4] = new TLatex(2.5+0.2,   1.27e3,"c");
  latex[5] = new TLatex(3.5+0.2, 172.76e3,"t");
  latex[6] = new TLatex(1.5+0.2,   2*4.67,"d");
  latex[7] = new TLatex(2.5+0.2,   0.3*93,"s");
  latex[8] = new TLatex(3.5+0.2,   4.18e3,"b");
  for(int i=0; i<9; i++){
    latex[i]->SetTextColor(color[(int)(i/3)]);
    latex[i]->Draw();
  }
  
  TBox *box[3];
  box[0] = new TBox(0.25,0.90*1e-7, 6.05,1.05*1e-7);
  box[1] = new TBox(5.95,0.90*1e-7, 6.05,1.05*1e10 );
  box[2] = new TBox(0.25,0.95*1e10, 6.05,1.05*1e10 );
  for(int i=0; i<3; i++){
    box[i]->SetFillColor(0);
    box[i]->SetLineColor(0);
    box[i]->Draw();
  }

  TLine *line = new TLine(1.5,2e-6,3.5,2e-6);
  line->SetLineColor(color[3]);
  line->Draw();

  TArrow *arr = new TArrow(2.5,2e-6,2.5,2e-7, 0.03,"|>");
  arr->SetLineColor(color[3]);
  arr->SetFillColor(color[3]);
  arr->Draw();

  TText *text = new TText(2.5,4e-6,"neutrinos");
  text->SetTextColor(color[3]);
  text->Draw();

  TEllipse *el = new TEllipse(2.5,3e9, 1.5,2e9);
  el->SetFillStyle(0);
  el->SetLineColor(7);
  el->Draw();

  TText *text2 = new TText(1.5,1e8,"Majorana neutrinos ?");
  text2->SetTextColor(7);
  text2->Draw();
}
