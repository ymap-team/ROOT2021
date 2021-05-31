{
  gStyle->SetOptStat(0);

  TCanvas *c = new TCanvas("c","c",1400,800);
  c->Divide(2,2,0.001,0.001);

  double t0 = 1618559095;
  TH2D *h2 = new TH2D("hist","2 jigen hisuto", 100,t0,t0+1000000, 20,0,20);
  TH1D *h1_kikan = new TH1D("kikan","kikan", 20,0,20);
  TH1D *h1_jikan = new TH1D("jikan","jikan", 100,t0,t0+1000000);
  ifstream ifs("data.dat");
  double dummy, t, shozoku_id;
  while(ifs >> dummy >> t >> dummy >> shozoku_id){
    for(int i=0; i<8; i++) ifs >> dummy;
    h2->Fill(t+t0, shozoku_id);
    h1_kikan->Fill(shozoku_id);
    h1_jikan->Fill(t+t0);
  }
  TString label[20] = {"others","tohoku","osaka","tokyo","tsukuba","nagoya",
		       "hiroshima","kobe","kyushu","tokyokogyo","ritsumeikan",
		       "tokyorika","soukendai","yokokoku","kyoto","waseda",
		       "tokushima","oosakashiritsu","gifu","iwate"};
  for(int i=0; i<20; i++) h2->GetYaxis()->SetBinLabel(1+i, label[i]);
  h2->GetXaxis()->SetTimeDisplay(1);
  h2->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%H:%M}");
  h2->GetXaxis()->SetTimeOffset(32400,"gmt");
  h2->GetXaxis()->SetNdivisions(420);
  h2->GetXaxis()->SetLabelOffset(0.03);
  for(int i=0; i<20; i++) h1_kikan->GetXaxis()->SetBinLabel(1+i, label[i]);
  h1_jikan->GetXaxis()->SetTimeDisplay(1);
  h1_jikan->GetXaxis()->SetTimeFormat("#splitline{%m/%d}{%H:%M}");
  h1_jikan->GetXaxis()->SetTimeOffset(32400,"gmt");
  h1_jikan->GetXaxis()->SetNdivisions(420);
  h1_jikan->GetXaxis()->SetLabelOffset(0.03);
  c->cd(2);
  h2->Draw("COLZ");

  c->cd(1);
  h1_kikan->Draw("hbar");

  c->cd(4);
  h1_jikan->Draw();
  
  c->cd(3);
  TPaveText *pt = new TPaveText(0.1,0.1,0.9,0.5);
  pt->AddText("kazu");
  pt->AddText(Form("t0=%g",t0));
  pt->AddText(Form("N=%g",h2->GetEntries()));
  pt->Draw();
  TPaveText *pt2 = new TPaveText(0.1,0.5,0.9,0.9);
  pt2->AddText("sankasha");
  pt2->SetFillColor(3);
  pt2->Draw();
}
