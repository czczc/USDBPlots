// From Xin

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");
  TF1 *f3 = new TF1("f3",qpol2,0,20,3);
  Double_t par[3],par_err[3];
  ifstream infile("par.dat");
  for (Int_t i=0;i!=3;i++){
    infile >> par[i] >> par_err[i];
  }
  f3->SetParameters(par);

  TFile *file = new TFile("save_file.root");
  TGraph *g_data = (TGraph*)file->Get("gdata");

  TCanvas c1("c1", "c1", 800, 600);
  g_data->SetMarkerStyle(24);
  g_data->SetMarkerSize(1);
  g_data->GetXaxis()->SetTitle("E_{vis} [MeV]");
  g_data->GetYaxis()->SetTitle("E_{rec} / E_{vis}");
  g_data->SetTitle("Electronics Nonlinearity");
  g_data->Draw("ap");
  f3->SetLineColor(kRed);
  f3->Draw("same");

  TString name("ElectronicsGamma");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }

}

Double_t qpol2(Double_t *x, Double_t *par){
  Double_t results;
  Double_t qx = *x;
  Double_t qpar1 = *par;
  Double_t qpar2 = *(par+1);
  Double_t qpar3 = *(par+2);

  results = qpar1 + qpar2*qx + qpar3*qx*qx;
  if (qx > -qpar2/2./qpar3){
    results = qpar1 + qpar2 *(-qpar2/2./qpar3) + qpar3*pow(-qpar2/2./qpar3,2);
  }

  return results;
}
