#include <gtk/gtk.h>
//////////////////////////////////////////////////////
///ESPACE ADMINE
//////////////////////////////////////////////////////

void
on_buttonDec_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonValider_clicked               (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_Admin_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_agent_de_foyer_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_agent_de_restaurant_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_nutritionniste_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_technicien_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_etudiant_clicked       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAfret_clicked                 (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_treeviewAfficher_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonRetourAj_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttoncnx_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodifierRetour_clicked        (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonretourmodifier1_clicked       (GtkWidget	*objet_graphique,
                                        gpointer         user_data);


void
on_buttonModifier1_clicked             (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonretourchercher_clicked        (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonChercher_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonRetourAT_clicked              (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_treeviewAT_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonretourSupprimer_clicked       (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

void
on_buttonverifier_exist_clicked        (GtkWidget	*objet_graphique,
                                        gpointer         user_data);

//////////////////////////////////////////////////////////
////ESPACE TECHNICHIEN
//////////////////////////////////////////////////////////
void
on_affichercapteur_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_deconnecterET_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_chercherc_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifierc_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimerc_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajouterc_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeviewaffcapteur_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_rb1_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb2_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb3_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb4_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb5_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confmodf_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonannulerm_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_confirmerm_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonajoutc_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rb6_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb7_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb8_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb9_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb10_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Annulera_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonannulerS_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonsuppc_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonrc_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonanuulerR_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_verifierexiste_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rb6_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb7_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb8_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb9_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb10_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb5_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb4_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb3_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb2_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rb1_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

//////////////////////////////////////////////////////////
///DASHBOARD
//////////////////////////////////////////////////////////




void
on_meilleur_menu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_service_reclame_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_listalarme_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_capt_defc_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonalleramonespace_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonespaceetudiant_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


////////////////////////////////////////////////////
///
////////////////////////////////////////////////////
