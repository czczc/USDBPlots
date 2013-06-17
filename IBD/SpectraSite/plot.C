void plot(const char* type = "eps")
{
  gROOT->ProcessLine(".x ../../style.C");

  TFile *f = new TFile("../../SharedRootFiles/Osc.root");

  TH1D *data[6];
  TH1D *predOsc[6];
  TH1D *acc[6];
  TH1D *li9[6];
  TH1D *fsn[6];
  TH1D *afn[6];
  TH1D *amc[6];

  data[0] = (TH1D*)f->Get("ibd_spectrum_site1_det1");
  data[1] = (TH1D*)f->Get("ibd_spectrum_site1_det2");
  data[2] = (TH1D*)f->Get("ibd_spectrum_site2_det1");
  data[3] = (TH1D*)f->Get("ibd_spectrum_site4_det1");
  data[4] = (TH1D*)f->Get("ibd_spectrum_site4_det2");
  data[5] = (TH1D*)f->Get("ibd_spectrum_site4_det3");

  predOsc[0] = (TH1D*)f->Get("total_spectrum_expected_AD1");
  predOsc[1] = (TH1D*)f->Get("total_spectrum_expected_AD2");
  predOsc[2] = (TH1D*)f->Get("total_spectrum_expected_AD3");
  predOsc[3] = (TH1D*)f->Get("total_spectrum_expected_AD4");
  predOsc[4] = (TH1D*)f->Get("total_spectrum_expected_AD5");
  predOsc[5] = (TH1D*)f->Get("total_spectrum_expected_AD6");

  acc[0] = (TH1D*)f->Get("acc_spectrum_expected_AD1");
  acc[1] = (TH1D*)f->Get("acc_spectrum_expected_AD2");
  acc[2] = (TH1D*)f->Get("acc_spectrum_expected_AD3");
  acc[3] = (TH1D*)f->Get("acc_spectrum_expected_AD4");
  acc[4] = (TH1D*)f->Get("acc_spectrum_expected_AD5");
  acc[5] = (TH1D*)f->Get("acc_spectrum_expected_AD6");

  li9[0] = (TH1D*)f->Get("li9he8_spectrum_expected_AD1");
  li9[1] = (TH1D*)f->Get("li9he8_spectrum_expected_AD2");
  li9[2] = (TH1D*)f->Get("li9he8_spectrum_expected_AD3");
  li9[3] = (TH1D*)f->Get("li9he8_spectrum_expected_AD4");
  li9[4] = (TH1D*)f->Get("li9he8_spectrum_expected_AD5");
  li9[5] = (TH1D*)f->Get("li9he8_spectrum_expected_AD6");

  fsn[0] = (TH1D*)f->Get("fastn_spectrum_expected_AD1");
  fsn[1] = (TH1D*)f->Get("fastn_spectrum_expected_AD2");
  fsn[2] = (TH1D*)f->Get("fastn_spectrum_expected_AD3");
  fsn[3] = (TH1D*)f->Get("fastn_spectrum_expected_AD4");
  fsn[4] = (TH1D*)f->Get("fastn_spectrum_expected_AD5");
  fsn[5] = (TH1D*)f->Get("fastn_spectrum_expected_AD6");

  amc[0] = (TH1D*)f->Get("amc_spectrum_expected_AD1");
  amc[1] = (TH1D*)f->Get("amc_spectrum_expected_AD2");
  amc[2] = (TH1D*)f->Get("amc_spectrum_expected_AD3");
  amc[3] = (TH1D*)f->Get("amc_spectrum_expected_AD4");
  amc[4] = (TH1D*)f->Get("amc_spectrum_expected_AD5");
  amc[5] = (TH1D*)f->Get("amc_spectrum_expected_AD6");

  afn[0] = (TH1D*)f->Get("alphan_spectrum_expected_AD1");
  afn[1] = (TH1D*)f->Get("alphan_spectrum_expected_AD2");
  afn[2] = (TH1D*)f->Get("alphan_spectrum_expected_AD3");
  afn[3] = (TH1D*)f->Get("alphan_spectrum_expected_AD4");
  afn[4] = (TH1D*)f->Get("alphan_spectrum_expected_AD5");
  afn[5] = (TH1D*)f->Get("alphan_spectrum_expected_AD6");


  TH1D *data_site1 = data[0]->Clone("data_site1");
  data_site1->GetXaxis()->SetTitle("Prompt Energy [MeV]");
  data_site1->GetYaxis()->SetTitle("Events / 50KeV");
  data_site1->SetTitle("IBDs at EH1");

  TH1D *data_site2 = data[2]->Clone("data_site2");
  data_site2->GetXaxis()->SetTitle("Prompt Energy [MeV]");
  data_site2->GetYaxis()->SetTitle("Events / 50KeV");
  data_site2->SetTitle("IBDs at EH2");

  TH1D *data_site3 = data[3]->Clone("data_site3");
  data_site3->GetXaxis()->SetTitle("Prompt Energy [MeV]");
  data_site3->GetYaxis()->SetTitle("Events / 50KeV");
  data_site3->SetTitle("IBDs at EH3");

  TH1D *pred_site1 = predOsc[0]->Clone("pred_site1");
  THStack *hs_site1 = new THStack("hs_site1", "");
  TH1D *acc_site1  = acc[0]->Clone("acc_site1");
  TH1D *li9_site1  = li9[0]->Clone("li9_site1");
  TH1D *fsn_site1  = fsn[0]->Clone("fsn_site1");
  TH1D *amc_site1  = amc[0]->Clone("amc_site1");
  TH1D *afn_site1  = afn[0]->Clone("afn_site1");

  TH1D *pred_site2 = predOsc[2]->Clone("pred_site2");
  THStack *hs_site2 = new THStack("hs_site2", "");
  TH1D *acc_site2  = acc[2]->Clone("acc_site2");
  TH1D *li9_site2  = li9[2]->Clone("li9_site2");
  TH1D *fsn_site2  = fsn[2]->Clone("fsn_site2");
  TH1D *amc_site2  = amc[2]->Clone("amc_site2");
  TH1D *afn_site2  = afn[2]->Clone("afn_site2");

  TH1D *pred_site3 = predOsc[3]->Clone("pred_site3");
  THStack *hs_site3 = new THStack("hs_site3", "");
  TH1D *acc_site3  = acc[3]->Clone("acc_site3");
  TH1D *li9_site3  = li9[3]->Clone("li9_site3");
  TH1D *fsn_site3  = fsn[3]->Clone("fsn_site3");
  TH1D *amc_site3  = amc[3]->Clone("amc_site3");
  TH1D *afn_site3  = afn[3]->Clone("afn_site3");

  data_site1->Reset();
  pred_site1->Reset();
  acc_site1->Reset();
  li9_site1->Reset();
  fsn_site1->Reset();
  amc_site1->Reset();
  afn_site1->Reset();

  data_site2->Reset();
  pred_site2->Reset();
  acc_site2->Reset();
  li9_site2->Reset();
  fsn_site2->Reset();
  amc_site2->Reset();
  afn_site2->Reset();

  data_site3->Reset();
  pred_site3->Reset();
  acc_site3->Reset();
  li9_site3->Reset();
  fsn_site3->Reset();
  amc_site3->Reset();
  afn_site3->Reset();


  pred_site1->SetLineColor(2);
  pred_site1->SetMarkerColor(2);

  acc_site1->SetLineColor(9);
  acc_site1->SetMarkerColor(9);
  acc_site1->SetFillColor(9);

  li9_site1->SetLineColor(5);
  li9_site1->SetMarkerColor(5);
  li9_site1->SetFillColor(5);

  fsn_site1->SetLineColor(6);
  fsn_site1->SetMarkerColor(6);
  fsn_site1->SetFillColor(6);

  amc_site1->SetLineColor(7);
  amc_site1->SetMarkerColor(7);
  amc_site1->SetFillColor(7);

  afn_site1->SetLineColor(8);
  afn_site1->SetLineColor(8);
  afn_site1->SetFillColor(8);



  pred_site2->SetLineColor(2);
  pred_site2->SetMarkerColor(2);

  acc_site2->SetLineColor(9);
  acc_site2->SetMarkerColor(9);
  acc_site2->SetFillColor(9);

  li9_site2->SetLineColor(5);
  li9_site2->SetMarkerColor(5);
  li9_site2->SetFillColor(5);

  fsn_site2->SetLineColor(6);
  fsn_site2->SetMarkerColor(6);
  fsn_site2->SetFillColor(6);

  amc_site2->SetLineColor(7);
  amc_site2->SetMarkerColor(7);
  amc_site2->SetFillColor(7);

  afn_site2->SetLineColor(8);
  afn_site2->SetLineColor(8);
  afn_site2->SetFillColor(8);


  pred_site3->SetLineColor(2);
  pred_site3->SetMarkerColor(2);

  acc_site3->SetLineColor(9);
  acc_site3->SetMarkerColor(9);
  acc_site3->SetFillColor(9);

  li9_site3->SetLineColor(5);
  li9_site3->SetMarkerColor(5);
  li9_site3->SetFillColor(5);

  fsn_site3->SetLineColor(6);
  fsn_site3->SetMarkerColor(6);
  fsn_site3->SetFillColor(6);

  amc_site3->SetLineColor(7);
  amc_site3->SetMarkerColor(7);
  amc_site3->SetFillColor(7);

  afn_site3->SetLineColor(8);
  afn_site3->SetLineColor(8);
  afn_site3->SetFillColor(8);


  for (int i=0; i<2; i++) {
    data_site1->Add(data[i]);
    pred_site1->Add(predOsc[i]);
    acc_site1->Add(acc[i]);
    li9_site1->Add(li9[i]);
    fsn_site1->Add(fsn[i]);
    amc_site1->Add(amc[i]);
    afn_site1->Add(afn[i]);
  }

  for (int i=2; i<3; i++) {
    data_site2->Add(data[i]);
    pred_site2->Add(predOsc[i]);
    acc_site2->Add(acc[i]);
    li9_site2->Add(li9[i]);
    fsn_site2->Add(fsn[i]);
    amc_site2->Add(amc[i]);
    afn_site2->Add(afn[i]);
  }

  for (int i=3; i<6; i++) {
    data_site3->Add(data[i]);
    pred_site3->Add(predOsc[i]);
    acc_site3->Add(acc[i]);
    li9_site3->Add(li9[i]);
    fsn_site3->Add(fsn[i]);
    amc_site3->Add(amc[i]);
    afn_site3->Add(afn[i]);
  }

  hs_site1->Add(fsn_site1);
  hs_site1->Add(afn_site1);
  hs_site1->Add(amc_site1);
  hs_site1->Add(li9_site1);
  hs_site1->Add(acc_site1);

  hs_site2->Add(fsn_site2);
  hs_site2->Add(afn_site2);
  hs_site2->Add(amc_site2);
  hs_site2->Add(li9_site2);
  hs_site2->Add(acc_site2);

  hs_site3->Add(fsn_site3);
  hs_site3->Add(afn_site3);
  hs_site3->Add(amc_site3);
  hs_site3->Add(li9_site3);
  hs_site3->Add(acc_site3);

  TCanvas c1("c1", "c1", 800, 800);
  TPad *can_1 = new TPad("can_1", "can_1",0, 0.66, 1, 0.99);
  TPad *can_2 = new TPad("can_2", "can_2",0, 0.33, 1, 0.66);
  TPad *can_3 = new TPad("can_3", "can_3",0, 0, 1, 0.33);

  can_1->Draw();
  can_1->cd();
  can_1->SetBottomMargin(1e-05);
  can_1->SetFrameBorderMode(0);
  can_1->SetBorderMode(0);
  data_site1->Draw();
  data_site1->SetTitle("");
  hs_site1->Draw("same");
  data_site1->Draw("same");
  // pred_site1->Draw("same");
  data_site1->GetXaxis()->SetLabelSize(0.09);
  data_site1->GetYaxis()->SetNdivisions(508);
  data_site1->GetYaxis()->SetTitleSize(0.08);
  data_site1->GetYaxis()->SetLabelSize(0.08);
  data_site1->GetYaxis()->SetTitleOffset(0.6);
  data_site1->GetYaxis()->CenterTitle(true);
  TLegend leg(0.65,0.85-0.20,0.85,0.85);
  leg.AddEntry(data_site1, " EH1", "lp");
  leg.AddEntry(acc_site1, " Acc. Bkgd", "f");
  leg.SetFillColor(kWhite);
  leg.Draw();
  can_1->Modified();
  c1.cd();

  can_2->Draw();
  can_2->cd();
  can_2->SetTopMargin(1e-05);
  can_2->SetBottomMargin(1e-05);
  can_2->SetFrameBorderMode(0);
  can_2->SetBorderMode(0);
  data_site2->Draw();
  hs_site2->Draw("same");
  data_site2->SetTitle("");
  // data_site2->Draw("same");
  // pred_site2->Draw("same");
  data_site2->GetXaxis()->SetLabelSize(0.09);
  data_site2->GetYaxis()->SetNdivisions(508);
  data_site2->GetYaxis()->SetTitleSize(0.08);
  data_site2->GetYaxis()->SetLabelSize(0.08);
  data_site2->GetYaxis()->SetTitleOffset(0.6);
  data_site2->GetYaxis()->CenterTitle(true);
  TLegend leg2(0.65,0.85-0.20,0.85,0.85);
  leg2.AddEntry(data_site2, " EH2", "lp");
  leg2.AddEntry(acc_site2, " Acc. Bkgd", "f");
  leg2.SetFillColor(kWhite);
  leg2.Draw();
  can_2->Modified();
  c1.cd();

  can_3->Draw();
  can_3->cd();
  can_3->SetTopMargin(1e-05);
  can_3->SetFrameBorderMode(0);
  can_3->SetBottomMargin(0.3);
  can_3->SetBorderMode(0);
  data_site3->Draw();
  hs_site3->Draw("same");
  data_site3->SetTitle("");
  // data_site3->Draw("same");
  // pred_site3->Draw("same");
  data_site3->GetXaxis()->SetTitle("Reconstructed Energy [MeV]");
  data_site3->GetXaxis()->SetTitleSize(0.09);
  data_site3->GetXaxis()->SetTitleOffset(1.45);
  data_site3->GetXaxis()->SetLabelSize(0.09);
  data_site3->GetXaxis()->Draw();
  data_site3->GetYaxis()->SetNdivisions(508);
  data_site3->GetYaxis()->SetLabelSize(0.08);
  data_site3->GetYaxis()->SetTitleSize(0.08);
  data_site3->GetYaxis()->SetTitleOffset(0.6);
  data_site3->GetYaxis()->CenterTitle(true);
  can_3->RedrawAxis();
  TLegend leg3(0.65,0.85-0.20,0.85,0.85);
  leg3.AddEntry(data_site3, " EH3", "lp");
  leg3.AddEntry(acc_site3, " Acc. Bkgd", "f");
  leg3.SetFillColor(kWhite);
  leg3.Draw();
  can_3->Modified();
  c1.cd();

  TString name("SpectraSite");
  // print 3 figures by default
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}
