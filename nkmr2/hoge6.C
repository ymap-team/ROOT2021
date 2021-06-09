#include "TH1.h"
#include "TRint.h"
int main(){
  TRint app("app", 0, 0);

  TH1D *h = new TH1D("h","h",10,0,10);
  h->Fill(5);
  h->Draw();

  app.Run();
}
