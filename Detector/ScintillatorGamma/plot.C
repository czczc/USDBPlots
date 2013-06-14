// From Chao Zhang

void plot(const char* type = "eps") {
  gROOT->ProcessLine(".x ../../style.C");

  const int N = 11;
  double m[N][5] = {
    // Etrue, Evis, Erec, err, elec_corr,
    {(1.1732+1.3325)/2, 2.48987/2, 2.45313/2, 0.0142478, 0.986268},  // Co
    {0.511, 0.942836/2, 0.9545/2, 0.00996527, 1.00771}, // Ge
    {0.6617, 0.623793, 0.63357, 0.00661466, 1.01259},  // Cs
    {1.4608, 1.46895, 1.46877, 0.00485984, 0.999995},  // K
    {0.8348, 0.803524, 0.81866, 0.00854706, 1.00982}, // Mn
    {2.2233, 2.31941, 2.28652, 0.00724191, 0.988447}, // nH
    {2.6145, 2.75554, 2.7097, 0.0158014, 0.982964}, // Tl
    {(5.9204+6.0185)/2, 6.52355, 6.08752, 0.0640191, 0.947998}, // nFe1
    {(7.6311+7.6455)/2, 8.38005, 7.86949, 0.082279, 0.938946}, // nFe2
    {4.9453, 5.3247, 5.11361, 0.0167142, 0.956712}, // nC
    {6.1286, 6.70064, 6.34229, 0.0200888, 0.946902}, // O*
    // {4.4389, 4.96708, 4.76921, 0.0501321, 0.959747}, // PuCC*
    // {4.4389, 5.43057, 4.98181, 0.194251, 0.955851}, // AmBeC*
    // n-Gd  8.55249 8.02561 0.0241169 0.938379

  };

  double Etrue[N];
  double Evis[N];
  double ratio[N];
  double err[N];
  double xerr[N];
  for (int i=0; i!=N; i++) {
    Etrue[i] = m[i][0];
    Evis[i] = m[i][2] / m[i][4];
    ratio[i] = Evis[i]/Etrue[i];
    err[i] = m[i][3] / m[i][4] / Etrue[i];
    xerr[i] = 0;
  }

  TCanvas c1("c1", "c1", 800, 600);

  ifstream infile("photon.dat");
  double x[19];
  double y[19];
  for (int i=0; i!=19; i++){
    infile >> x[i] >> y[i];
  }
  infile.close();
  TGraph *g_photon = new TGraph(19, x, y);
  g_photon->Draw("ac");
  g_photon->GetXaxis()->SetTitle("E_{true} [MeV]");
  g_photon->GetYaxis()->SetTitle("E_{vis} / E_{true}");
  g_photon->SetTitle("Scintillator Nonlinearity for Gamma");
  g_photon->SetLineWidth(2);
  g_photon->SetLineColor(kRed);

  TGraphErrors *g_data = new TGraphErrors(N, Etrue, ratio, xerr, err);
  g_data->SetMarkerStyle(24);
  g_data->SetMarkerSize(1);
  g_data->Draw("p, same");

  TString name("ScintillatorGamma");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }

}