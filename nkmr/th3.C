{
  TH3D *h = new TH3D("","", 20,0,100, 20,0,100, 20,0,100);
  for(int i=0; i<10000; i++) h->Fill(gRandom->Gaus(40,10), gRandom->Gaus(50,2), gRandom->Gaus(60,2));
  h->Draw("box");
}
