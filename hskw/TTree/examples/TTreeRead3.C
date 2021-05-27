void TTreeRead3(){
  TChain *chain = new TChain("tree");
  chain->Add("TTreeTest.root");
  chain->Add("TTreeTest1.root");
  chain->Add("TTreeTest2.root");

  chain->Draw("year","","");
}
