{
  TGraph2D *g = new TGraph2D();
  for(int i=0; i<1000; i++){
    double x = gRandom->Uniform(-5,5);
    double y = gRandom->Uniform(-5,5);
    double z = (x*x+y*y)*(x*x+y*y-25.0);
    g->SetPoint(i,x,y,z);
  }
  //g->Draw();
  g->Draw("surf");
}
