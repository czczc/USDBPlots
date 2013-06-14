void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");
  TCanvas c1("c1", "c1", 800, 600);

  TFile f("mcs_nGd.root");
  TH3F *data = (TH3F*)f.Get("h2");

  data->SetTitle("nGd Energy at Various MCS PuC Source Location");
  data->Draw("colz");
  gPad->SetPhi(15);

  TString name("MCS_Uniformity");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }

}