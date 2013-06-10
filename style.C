{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleStyle(0);
  gStyle->SetTitleOffset(1.1, "x");
  gStyle->SetTitleOffset(1.25, "y");
  gStyle->SetHistLineWidth(2);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(0);
  gStyle->SetPalette(1);
  gROOT->UseCurrentStyle();
  gROOT->ForceStyle();
}