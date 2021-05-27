void TTreeRead2(){

  TFile file("TTreeTest.root");
  TTree* tree=(TTree*)file.Get("tree");

  int id, institute, year, env, network, nskill;
  double dt;
  bool ML, unix, shell, ROOT, cpp, python;

  tree->SetBranchAddress("id",        &id);
  tree->SetBranchAddress("dt",        &dt);
  tree->SetBranchAddress("year",      &year);
  tree->SetBranchAddress("nskill",    &nskill);
  tree->SetBranchAddress("ROOT",      &ROOT);
  
  for( int i=0; i<tree->GetEntries(); i++ ){
    tree->GetEntry(i);
    if(year==0) cout << nskill << " " << ROOT << endl;
  }

  tree->Draw("id:dt","","L");
}
