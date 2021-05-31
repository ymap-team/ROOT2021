{
  TH2D *h2 = new TH2D("h2","h2", 50,-1,1, 50,-1,1);
  for(int i=0; i<10000; i++){
    double costheta = gRandom->Uniform(-1,1);
    double phi = gRandom->Uniform(0,2*TMath::Pi());
    double theta = TMath::ACos(costheta);
    double x = TMath::Cos(phi)*TMath::Sin(theta);
    double y = TMath::Sin(phi)*TMath::Sin(theta);
    double z = costheta;
    h2->Fill(x,y);
  }
  h2->Draw("COLZ");
}
