void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile *file = new TFile("nominal.root");
  TGraph *g_electron = (TGraph*)file->Get("electron");
  TGraph *g_photon = (TGraph*)file->Get("photon");
  TGraph *g_positron = (TGraph*)file->Get("positron");
  TGraph *g_proton = (TGraph*)file->Get("proton");
  TGraph *g_alpha = (TGraph*)file->Get("alpha");

  TCanvas c1("c1", "c1", 800, 600);
  g_electron->SetLineColor(kBlue);
  g_electron->Draw("AL");

  g_photon->SetLineColor(kBlack);
  g_photon->Draw("c,same");

  g_positron->SetLineColor(kRed);
  g_positron->Draw("Lsame");

  g_proton->SetLineColor(kMagenta);
  g_proton->Draw("Lsame");

  g_alpha->SetLineColor(kCyan+1);
  g_alpha->Draw("Lsame");

  g_electron->GetYaxis()->SetRangeUser(0.,1.2);
  g_electron->GetXaxis()->SetRangeUser(0.,10);
  g_electron->GetXaxis()->SetTitle("True Energy [MeV]");
  g_electron->GetYaxis()->SetTitle("Reconstructed Energy / True Energy");
  g_electron->SetTitle("Nonlinearity of All Particles");


  TLegend leg(0.70,0.75-0.25,0.80,0.75);
  leg.AddEntry(g_electron, "  e^{-}", "l");
  leg.AddEntry(g_photon,   "  #gamma", "l");
  leg.AddEntry(g_positron, "  e^{+}", "l");
  leg.AddEntry(g_proton,   "  p", "l");
  leg.AddEntry(g_alpha,    "  #alpha", "l");
  leg.SetFillColor(kWhite);
  // leg.SetBorderSize(1);
  leg.Draw();

  TString name("ScintillatorNL");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
