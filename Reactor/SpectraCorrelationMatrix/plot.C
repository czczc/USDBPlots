void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");
  TCanvas c1("c1", "c1", 10, 10, 660, 540);
  // TCanvas c1("c1", "c1", 800, 600);
  // gStyle->SetOptStat(0);
  // c1->SetFillColor(0);
  // c1->SetBorderMode(0);
  c1.SetBorderSize(2);
  c1.SetRightMargin(0.15);
  c1.SetFrameLineWidth(2);
  c1.SetFrameBorderMode(0);
  c1.SetFrameLineWidth(2);
  c1.SetFrameBorderMode(0);
  // gStyle->SetNumberContours(99);

  TFile matrix("covarMerged.root");
  TMatrixD corr = *(TMatrixD*)matrix.Get("corrAllEbins");

  corr.Draw("COLZ");

  TString name("SpectraCorrelationMatrix");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
