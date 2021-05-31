{
  double gen[3] = {1.5, 2.5, 3.5};
  double mass[3] = {2.16, 93, 4.18e3};
  double ex[3] = {0.1, 0.2, 0.3};
  double ey[3] = {0.49, 11, 0.03e3};
  TGraphErrors *g = new TGraphErrors(3, gen, mass, ex, ey);
  g->Draw();
}
