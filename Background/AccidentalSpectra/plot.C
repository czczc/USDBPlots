// From Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("merge_single.root");
  TH1F *hp1 = (TH1F*)f1.Get("hp1");
  hp1->Scale(1./hp1->Integral());

  TCanvas c1("c1", "c1", 800, 600);
  hp1->Draw("");
  hp1->GetXaxis()->SetTitle("E [MeV]");
  hp1->SetTitle("Accidental Spectrum");

  gPad->SetLogy();

  TString name("AccidentalSpectra");
  c1.SaveAs(name + "." + type);
}