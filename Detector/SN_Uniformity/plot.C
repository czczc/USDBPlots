void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");
  TCanvas c1("c1", "c1", 800, 600);
  c1.SetRightMargin(0.14);

  TFile f("nGd_Grid.root");
  TH2F *data = (TH2F*)f.Get("Gdenergy_ratio_Ad1_hist");

  data->SetTitle("nGd Energy Uniformity from Spallation Neutron");
  data->Draw("colz, text");
  data->GetZaxis()->SetRangeUser(1-0.008,1+0.008);
  data->GetXaxis()->SetTitle("R^{2} [m^{2}]");
  data->GetYaxis()->SetTitle("Z [m]");
  data->GetXaxis()->SetRangeUser(0, 2.5);
  data->GetYaxis()->SetRangeUser(-1.6, 1.6);

  TString name("SN_Uniformity");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }

}