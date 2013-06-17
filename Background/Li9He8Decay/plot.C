// From Jiajie Ling & Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("li9fit.root");
  TH1F *data = (TH1F*)f1.Get("h7");
  TF1 *fit = (TF1*)f1.Get("f1");

  TCanvas c1("c1", "c1", 800, 600);
  data->Draw("e");
  data->GetXaxis()->SetTitle("Time since muon [ms]");
  data->GetYaxis()->SetTitle("");
  data->GetXaxis()->SetRangeUser(0., 2000);
  // data->GetYaxis()->SetRangeUser(1, 550);
  data->SetTitle("^{9}Li / ^{8}He Decay");

  fit->SetLineColor(kRed);
  fit->Draw("same");
  // gPad->SetLogy();

  TString name("Li9He8Decay");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}