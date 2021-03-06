/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/Förderprojekte/openETCS/modeling/model/Scade/System/ObuFunctions/ManageLocationRelatedInformation/MLRI_Integration/KCG\kcg_s2c_config.txt
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "MLRI__recalculate_BG_location_astern_CalculateTrainPosition_Pkg_BG_relocation_Pkg.h"

/* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern */
void MLRI__recalculate_BG_location_astern_CalculateTrainPosition_Pkg_BG_relocation_Pkg(
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::BG_in */MLRI__positionedBG_T_TrainPosition_Types_Pck *BG_in,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::prevLinkedBG */MLRI__positionedBG_T_TrainPosition_Types_Pck *prevLinkedBG,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::refBG */MLRI__positionedBG_T_TrainPosition_Types_Pck *refBG,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::sumOfBestDistances */MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg *sumOfBestDistances,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::trainProperties */MLRI__trainProperties_T_TrainPosition_Types_Pck *trainProperties,
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::BG_out */MLRI__positionedBG_T_TrainPosition_Types_Pck *BG_out)
{
  MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg tmp1;
  MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg tmp;
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::_L181 */ MLRI__LocWithInAcc_T_Obu_BasicTypes_Pkg _L181;
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::_L195 */ kcg_bool _L195;
  /* CalculateTrainPosition_Pkg::BG_relocation_Pkg::recalculate_BG_location_astern::_L212 */ kcg_bool _L212;
  
  /* 1 */
  MLRI__add_2_Distances_BasicLocationFunctions_Pkg(
    &(*refBG).location,
    sumOfBestDistances,
    &tmp1);
  /* 1 */
  MLRI__calculateLocalBGInaccuracies_CalculateTrainPosition_Pkg_BG_relocation_Pkg(
    BG_in,
    trainProperties,
    &tmp);
  /* 1 */ MLRI__sub_2_distances_BasicLocationFunctions_Pkg(&tmp1, &tmp, &_L181);
  /* 1 */
  MLRI__sub_2_odoDistances_BasicLocationFunctions_Pkg(
    &(*prevLinkedBG).infoFromPassing.bgPosition.odo,
    &(*BG_in).infoFromPassing.bgPosition.odo,
    &tmp);
  /* 3 */
  MLRI__add_2_Distances_BasicLocationFunctions_Pkg(
    &(*BG_in).infoFromPassing.BG_centerDetectionInaccuraccuracies,
    &tmp,
    &tmp1);
  /* 3 */
  MLRI__sub_2_distances_BasicLocationFunctions_Pkg(
    &(*prevLinkedBG).location,
    &tmp1,
    &tmp);
  /* 1 */
  MLRI__overlapOf_2_Locations_BasicLocationFunctions_Pkg(
    &_L181,
    &tmp,
    &tmp1,
    &_L212);
  _L195 = (*BG_in).valid & (*BG_in).infoFromPassing.valid &
    (*prevLinkedBG).valid & (*prevLinkedBG).infoFromPassing.valid;
  MLRI__kcg_copy_positionedBG_T_TrainPosition_Types_Pck(BG_out, BG_in);
  if ((*BG_in).valid & (*refBG).valid & ((*BG_in).q_link ==
      MLRI__Q_LINK_Linked)) {
    if (_L212 & _L195) {
      MLRI__kcg_copy_LocWithInAcc_T_Obu_BasicTypes_Pkg(
        &(*BG_out).location,
        &tmp1);
    }
    else {
      MLRI__kcg_copy_LocWithInAcc_T_Obu_BasicTypes_Pkg(
        &(*BG_out).location,
        &_L181);
    }
  }
  else if (_L195) {
    MLRI__kcg_copy_LocWithInAcc_T_Obu_BasicTypes_Pkg(&(*BG_out).location, &tmp);
  }
  else {
    MLRI__kcg_copy_LocWithInAcc_T_Obu_BasicTypes_Pkg(
      &(*BG_out).location,
      &(*BG_in).location);
  }
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** MLRI__recalculate_BG_location_astern_CalculateTrainPosition_Pkg_BG_relocation_Pkg.c
** Generation date: 2014-12-12T12:03:54
*************************************************************$ */

