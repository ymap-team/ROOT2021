{
  TH2D *h2 = new TH2D("h2","Sendai, May, 2021;nisshou h;kion deg", 13,0,13, 11,11,22);
  ifstream ifs("tenki.dat");
  TString dummy;
  ifs >> dummy >> dummy;
  double x, y;
  while(ifs >> y >> x) h2->Fill(x, y);
  h2->Draw("COLZ");
  //h2->Draw("LEGO");
}
