void fitting1(){

  TH1D *h1 = new TH1D("h1", "histo from a gaussian", 100, -5, 5);

  TF1 *f1 = new TF1("f1","gaus", -10, 10);
  f1->SetParameters(1., 0.5, 1.);

  for( int i=0; i<10000; i++ ){
    h1->Fill(f1->GetRandom());
  }

  h1->Fit("gaus");
}
