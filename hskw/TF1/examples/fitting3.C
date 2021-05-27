void fitting3(){

  gStyle->SetOptFit(1111111);
  TF1 *f1 = new TF1("f1","gaus", 0, 20);
  TF1 *f2 = new TF1("f2","expo", 0, 20);
  f1->SetParameters(1., 10., 1.5);
  f2->SetParameters(1., -0.1);

  TH1D *h1 = new TH1D("h1", "summed up histogram", 200, 0, 20);
  h1->Sumw2();
  for(int i=0;i<10000;i++) h1->Fill(f1->GetRandom());
  for(int i=0;i<10000;i++) h1->Fill(f2->GetRandom());
  
  TF1 *fit2=new TF1("fit2","[0]*exp(-0.5*pow(((x-[1])/[2]),2.))+exp([3]+[4]*x)",0,20);
  fit2->SetParameters(100., 8., 1., 1., -0.1);
  h1->Fit(fit2);

  double params[5], parerrs[5];
  fit2->GetParameters(&params[0]);
  for(int i=0; i<5; i++) parerrs[i]=fit2->GetParError(i);
  for(int i=0;i<5;i++) cout << params[i] << " +/- " << parerrs[i] << endl;

  TF1 *f3 = new TF1("f3","gaus", 0, 20);
  TF1 *f4 = new TF1("f4","expo", 0, 20);
  f3->SetParameters(params[0], params[1], params[2]);
  f4->SetParameters(params[3], params[4]);
  f3->SetLineColor(kMagenta); f4->SetLineColor(kBlue);
  f3->Draw("same"); f4->Draw("same");
  
}
