void TTreeRead1(){

  TFile file("TTreeTest.root");
  //file.ls();

  TTree* tree=(TTree*)file.Get("tree");
  //tree->Scan();


  //tree->Draw("year");

  /*
  tree->Draw("nskill","year==0","");
  TH1D *h1 = new TH1D("h1","h1",6,0,6);
  h1->SetLineColor(kRed);
  tree->Draw("nskill>>h1","year!=0&&year!=6","same");
  */
  
  tree->Draw("id:dt","","L");

  //tree->Draw("year:nskill","year<6","colz");

}
