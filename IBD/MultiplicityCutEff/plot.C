// From Chao Zhang

void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile f1("mult_eff.root");
  TGraphErrors *g1 = (TGraphErrors*)f1.Get("MultEff_EH1-AD1");
  TGraphErrors *g2 = (TGraphErrors*)f1.Get("MultEff_EH1-AD2");
  TGraphErrors *g3 = (TGraphErrors*)f1.Get("MultEff_EH2-AD1");
  TGraphErrors *g4 = (TGraphErrors*)f1.Get("MultEff_EH3-AD1");
  TGraphErrors *g5 = (TGraphErrors*)f1.Get("MultEff_EH3-AD2");
  TGraphErrors *g6 = (TGraphErrors*)f1.Get("MultEff_EH3-AD3");

  int nPoints = g1->GetN();
  TCanvas c1("c1", "c1", 1200, 600);
  TH2F h("h", "", 10000, g1->GetX()[0]-3*86400, g1->GetX()[nPoints-1]+3*86400, 100, 0.97, 0.979);
  h.GetXaxis()->SetTimeDisplay(1);
  h.GetXaxis()->SetTimeFormat("%b %d");
  h.GetXaxis()->SetNdivisions(505);
  h.GetXaxis()->SetTimeOffset(8*60*60);
  h.GetYaxis()->SetTitle("Multiplicity Cut Effciency");
  h.Draw();

  g1->SetMarkerStyle(24);
  g1->SetMarkerColor(kBlack);
  g1->SetMarkerSize(1.0);
  g1->Draw("PZ, same");

  g2->SetMarkerStyle(24);
  g2->SetMarkerColor(kRed);
  g2->SetMarkerSize(1.0);
  g2->Draw("PZ, same");

  g3->SetMarkerStyle(24);
  g3->SetMarkerColor(kBlue);
  g3->SetMarkerSize(1.0);
  g3->Draw("PZ, same");

  g4->SetMarkerStyle(20);
  g4->SetMarkerColor(kBlack);
  g4->SetMarkerSize(1.0);
  g4->Draw("PZ, same");

  g5->SetMarkerStyle(20);
  g5->SetMarkerColor(kRed);
  g5->SetMarkerSize(1.0);
  g5->Draw("PZ, same");

  g6->SetMarkerStyle(20);
  g6->SetMarkerColor(kBlue);
  g6->SetMarkerSize(1.0);
  g6->Draw("PZ, same");

  TLegend leg1(0.71,0.99,0.85,0.99-3*0.06);
  TLegend leg2(0.85,0.99,0.99,0.99-3*0.06);
  leg1.SetFillColor(kWhite);
  leg1.SetBorderSize(1);
  leg2.SetFillColor(kWhite);
  leg2.SetBorderSize(1);

  leg1.AddEntry(g1, " EH1-AD1", "p");
  leg1.AddEntry(g2, " EH1-AD2", "p");
  leg1.AddEntry(g3, " EH2-AD1", "p");
  leg2.AddEntry(g4, " EH3-AD1", "p");
  leg2.AddEntry(g5, " EH3-AD2", "p");
  leg2.AddEntry(g6, " EH3-AD3", "p");

  leg1.Draw();
  leg2.Draw();

  TString name("MultiplicityCutEff");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}