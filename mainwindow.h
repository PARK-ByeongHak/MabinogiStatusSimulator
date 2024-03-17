#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>


// 샤인 오브 이웨카와 에코스톤, 토템 등의 효과들을 제외하고 최대 수치
#define HUMAN_LIFE_MAX 2500
#define HUMAN_MANA_MAX 2500
#define HUMAN_STAM_MAX 2500
#define HUMAN_STR_MAX 1900
#define HUMAN_INT_MAX 1900
#define HUMAN_DEX_MAX 1900
#define HUMAN_WILL_MAX 1900
#define HUMAN_LUCK_MAX 1900

enum AGE {
    AGE_10 = 0,
    AGE_11,
    AGE_12,
    AGE_13,
    AGE_14,
    AGE_15,
    AGE_16,
    AGE_17,
    AGE_18,
    AGE_19,
    AGE_20,
    AGE_21,
    AGE_22,
    AGE_23,
    AGE_24,
    AGE_25이상,
};
enum TALENT {
    Talent_Combat = 0,
    Talent_Mage,
    Talent_RangeCombat,
    Talent_CombatAlchemist,
    Talent_Monk,
    Talent_Bard,
    Talent_Marionette,
    Talent_Lance,
    Talent_TransemuteAlchemist,
    Talent_Shooter,
    Talent_Ninja,
    Talent_ChainBlade,
    Talent_Traveler,
    Talent_Trader,
    Talent_Priest,
    Talent_Cook,
    Talent_Blacksmith,
    Talent_Tailor,
    Talent_PotionMaker,
    Talent_Carpentry,
    Talent_PetHandler,
    Talent_MagiGraphy,
    Talent_Merlin,
    Talent_Diva,
    Talent_ProfessorJ,
    Talent_MasterChef,
    Talent_TreasureHunter
};
enum TALENT_BONUS {
    Talent_Bonus_Combat = 0,
    Talent_Bonus_Mage,
    Talent_Bonus_RangeCombat,
    Talent_Bonus_CombatAlchemist,
    Talent_Bonus_Monk,
    Talent_Bonus_Bard,
    Talent_Bonus_Marionette,
    Talent_Bonus_Lance,
    Talent_Bonus_TransemuteAlchemist,
    Talent_Bonus_Shooter,
    Talent_Bonus_Ninja,
    Talent_Bonus_ChainBlade,
    Talent_Bonus_Traveler,
    Talent_Bonus_Trader,
    Talent_Bonus_Priest,
    Talent_Bonus_Cook,
    Talent_Bonus_Blacksmith,
    Talent_Bonus_Tailor,
    Talent_Bonus_PotionMaker,
    Talent_Bonus_Carpentry,
    Talent_Bonus_PetHandler,
    Talent_Bonus_MagiGraphy,
    Talent_Bonus_Merlin,
    Talent_Bonus_Diva,
    Talent_Bonus_ProfessorJ,
    Talent_Bonus_MasterChef,
    Talent_Bonus_TreasureHunter
};

struct Stats {
    float statLife;
    float statMana;
    float statStam;
    float statStr;
    float statInt;
    float statDex;
    float statWill;
    float statLuck;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void Initialize();
    void InitializeStats();

private slots:
    void CalculateStats();

private:
    std::vector<Stats> vecStatAge;
    std::vector<Stats> vecStatTalent;
    std::vector<Stats> vecStatTalentBonus;
};
#endif // MAINWINDOW_H
