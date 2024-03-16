#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initialize();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    ui->comboAge->addItem("10");
    ui->comboAge->addItem("11");
    ui->comboAge->addItem("12");
    ui->comboAge->addItem("13");
    ui->comboAge->addItem("14");
    ui->comboAge->addItem("15");
    ui->comboAge->addItem("16");
    ui->comboAge->addItem("17");

    ui->comboTalent->addItem("근접 전투");
    ui->comboTalent->addItem("마법");
    ui->comboTalent->addItem("궁술");
    ui->comboTalent->addItem("전투 연금술");
    ui->comboTalent->addItem("격투술");
    ui->comboTalent->addItem("음악");
    ui->comboTalent->addItem("인형술");
    ui->comboTalent->addItem("랜스");
    ui->comboTalent->addItem("연성 연금술");
    ui->comboTalent->addItem("슈터");
    ui->comboTalent->addItem("인술");
    ui->comboTalent->addItem("체인 슬래시");
    ui->comboTalent->addItem("여행");
    ui->comboTalent->addItem("무역");
    ui->comboTalent->addItem("축복");
    ui->comboTalent->addItem("음식");
    ui->comboTalent->addItem("대장");
    ui->comboTalent->addItem("재단");
    ui->comboTalent->addItem("약품");
    ui->comboTalent->addItem("목공");
    ui->comboTalent->addItem("펫핸들러");
    ui->comboTalent->addItem("마기그래피");
    ui->comboTalent->addItem("멀린");
    ui->comboTalent->addItem("디바");
    ui->comboTalent->addItem("프로페서J");
    ui->comboTalent->addItem("마스터셰프");
    ui->comboTalent->addItem("트래저 헌터");

    InitializeStats();

connect(ui->btnCalculate,SIGNAL(clicked()),this,SLOT(CalculateStats()));

}
void MainWindow::CalculateStats()
{
    int currentStr = ui->leStr->text().toInt();
    int currentInt = ui->leInt->text().toInt();
    int currentDex = ui->leDex->text().toInt();
    int currentWill = ui->leWill->text().toInt();
    int currentLuck= ui->leLuck->text().toInt();
    int currentCombatLevel = ui->leCombatLevel->text().toInt()  - 1;
    int currentExplorerLevel = ui->leExplorerLevel->text().toInt() - 1;
    AGE currentAge = static_cast<AGE>(ui->comboAge->currentIndex());
    TALENT currentTalent = static_cast<TALENT>(ui->comboTalent->currentIndex());
    TALENT_BONUS currentTalentBonus = static_cast<TALENT_BONUS>(currentTalent);

    Stats currentStats;
    currentStats.statStr = currentStr + (vecStatAge.at(currentAge).statStr * currentCombatLevel) + (vecStatAge.at(currentAge).statStr * currentExplorerLevel) +
                           (vecStatTalent.at(currentTalent).statStr * currentCombatLevel) + (vecStatTalent.at(currentTalent).statStr * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statStr;
    currentStats.statInt = currentInt + (vecStatAge.at(currentAge).statInt * currentCombatLevel) + (vecStatAge.at(currentAge).statInt * currentExplorerLevel) +
                           (vecStatTalent.at(currentTalent).statInt * currentCombatLevel) + (vecStatTalent.at(currentTalent).statInt * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statInt;
    currentStats.statDex = currentDex + (vecStatAge.at(currentAge).statDex * currentCombatLevel) + (vecStatAge.at(currentAge).statDex * currentExplorerLevel) +
                           (vecStatTalent.at(currentTalent).statDex * currentCombatLevel) + (vecStatTalent.at(currentTalent).statDex * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statDex;
    currentStats.statWill = currentWill + (vecStatAge.at(currentAge).statWill * currentCombatLevel) + (vecStatAge.at(currentAge).statWill * currentExplorerLevel) +
                            (vecStatTalent.at(currentTalent).statWill * currentCombatLevel) + (vecStatTalent.at(currentTalent).statWill * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statWill;
    currentStats.statLuck = currentLuck + (vecStatAge.at(currentAge).statLuck * currentCombatLevel) + (vecStatAge.at(currentAge).statLuck * currentExplorerLevel) +
                            (vecStatTalent.at(currentTalent).statLuck * currentCombatLevel) + (vecStatTalent.at(currentTalent).statLuck * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statLuck;

    ui->lblStr->setText(QString("%1").arg(currentStats.statStr));
    ui->lblInt->setText(QString("%1").arg(currentStats.statInt));
    ui->lblDex->setText(QString("%1").arg(currentStats.statDex));
    ui->lblWill->setText(QString("%1").arg(currentStats.statWill));
    ui->lblLuck->setText(QString("%1").arg(currentStats.statLuck));

}
void MainWindow::InitializeStats() {

    // 나이 별 레벨업 시 얻는 스탯
    // 나이에 따라 레벨 업 할 때마다 아래의 스탯을 추가로 얻습니다.
    // 표기는 소수점을 가립니다.
    const float STAT_STR_10 = 0.5f, STAT_INT_10 = 0.0f, STAT_DEX_10 = 0.5f, STAT_WILL_10 = 0.75f, STAT_LUCK_10 = 0.75f;
    const float STAT_STR_11 = 0.5f, STAT_INT_11 = 0.0f, STAT_DEX_11 = 0.75f, STAT_WILL_11 = 0.75f, STAT_LUCK_11 = 0.5f;
    const float STAT_STR_12 = 0.5f, STAT_INT_12 = 0.0f, STAT_DEX_12 = 0.75f, STAT_WILL_12 = 0.75f, STAT_LUCK_12 = 0.5f;
    const float STAT_STR_13 = 0.5f, STAT_INT_13 = 0.0f, STAT_DEX_13 = 0.75f, STAT_WILL_13 = 0.75f, STAT_LUCK_13 = 0.25f;
    const float STAT_STR_14 = 0.5f, STAT_INT_14 = 0.25f, STAT_DEX_14 = 0.5f, STAT_WILL_14 = 0.5f, STAT_LUCK_14 = 0.25f;
    const float STAT_STR_15 = 0.5f, STAT_INT_15 = 0.5f, STAT_DEX_15 = 0.25f, STAT_WILL_15 = 0.5f, STAT_LUCK_15 = 0.0f;
    const float STAT_STR_16 = 0.5f, STAT_INT_16 = 0.5f, STAT_DEX_16 = 0.25f, STAT_WILL_16 = 0.5f, STAT_LUCK_16 = 0.0f;
    const float STAT_STR_17 = 0.5f, STAT_INT_17 = 0.75f, STAT_DEX_17 = 0.5f, STAT_WILL_17 = 0.25f, STAT_LUCK_17 = 0.0f;

    // 재능 별 레벨업 시 얻는 스탯
    // 재능에 따라 레벨 업 할 때마다 아래의 스탯을 추가로 얻습니다.
    // 표기는 소수점을 가립니다.
    const float STAT_STR_Talent_Combat = 0.5f,
        STAT_INT_Talent_Combat = 0.0f,
        STAT_DEX_Talent_Combat = 0.0f,
        STAT_WILL_Talent_Combat = 0.0f,
        STAT_LUCK_Talent_Combat = 0.0f;
    const float STAT_STR_Talent_Lance = 0.5f,
        STAT_INT_Talent_Lance = 0.0f,
        STAT_DEX_Talent_Lance = 0.0f,
        STAT_WILL_Talent_Lance = 0.0f,
        STAT_LUCK_Talent_Lance = 0.0f;
    const float STAT_STR_Talent_RangeCombat = 0.0f,
        STAT_INT_Talent_RangeCombat = 0.0f,
        STAT_DEX_Talent_RangeCombat = 0.5f,
        STAT_WILL_Talent_RangeCombat = 0.0f,
        STAT_LUCK_Talent_RangeCombat = 0.0f;
    const float STAT_STR_Talent_Mage = 0.0f,
        STAT_INT_Talent_Mage = 0.5f,
        STAT_DEX_Talent_Mage = 0.0f,
        STAT_WILL_Talent_Mage = 0.0f,
        STAT_LUCK_Talent_Mage = 0.0f;
    const float STAT_STR_Talent_Priest = 0.0f,
        STAT_INT_Talent_Priest = 0.5f,
        STAT_DEX_Talent_Priest = 0.0f,
        STAT_WILL_Talent_Priest = 0.0f,
        STAT_LUCK_Talent_Priest = 0.0f;
    const float STAT_STR_Talent_Monk = 0.0f,
        STAT_INT_Talent_Monk = 0.0f,
        STAT_DEX_Talent_Monk = 0.0f,
        STAT_WILL_Talent_Monk = 0.5f,
        STAT_LUCK_Talent_Monk = 0.0f;
    const float STAT_STR_Talent_Bard = 0.0f,
        STAT_INT_Talent_Bard = 0.0f,
        STAT_DEX_Talent_Bard = 0.0f,
        STAT_WILL_Talent_Bard = 0.0f,
        STAT_LUCK_Talent_Bard = 0.0f;
    const float STAT_STR_Talent_CombatAlchemist = 0.0f,
        STAT_INT_Talent_CombatAlchemist = 0.0f,
        STAT_DEX_Talent_CombatAlchemist = 0.0f,
        STAT_WILL_Talent_CombatAlchemist = 0.0f,
        STAT_LUCK_Talent_CombatAlchemist = 0.0f;
    const float STAT_STR_Talent_TransemuteAlchemist = 0.0f,
        STAT_INT_Talent_TransemuteAlchemist = 0.0f,
        STAT_DEX_Talent_TransemuteAlchemist = 0.0f,
        STAT_WILL_Talent_TransemuteAlchemist = 0.0f,
        STAT_LUCK_Talent_TransemuteAlchemist = 0.0f;
    const float STAT_STR_Talent_Trader = 0.0f,
        STAT_INT_Talent_Trader = 0.0f,
        STAT_DEX_Talent_Trader = 0.0f,
        STAT_WILL_Talent_Trader = 0.0f,
        STAT_LUCK_Talent_Trader = 0.5f;
    const float STAT_STR_Talent_Blacksmith = 0.0f,
        STAT_INT_Talent_Blacksmith = 0.0f,
        STAT_DEX_Talent_Blacksmith = 0.25f,
        STAT_WILL_Talent_Blacksmith = 0.0f,
        STAT_LUCK_Talent_Blacksmith = 0.0f;
    const float STAT_STR_Talent_Cook = 0.0f,
        STAT_INT_Talent_Cook = 0.0f,
        STAT_DEX_Talent_Cook = 0.25f,
        STAT_WILL_Talent_Cook = 0.0f,
        STAT_LUCK_Talent_Cook = 0.0f;
    const float STAT_STR_Talent_Tailor = 0.0f,
        STAT_INT_Talent_Tailor = 0.0f,
        STAT_DEX_Talent_Tailor = 0.25f,
        STAT_WILL_Talent_Tailor = 0.0f,
        STAT_LUCK_Talent_Tailor = 0.0f;
    const float STAT_STR_Talent_PotionMaker = 0.0f,
        STAT_INT_Talent_PotionMaker = 0.0f,
        STAT_DEX_Talent_PotionMaker = 0.0f,
        STAT_WILL_Talent_PotionMaker = 0.0f,
        STAT_LUCK_Talent_PotionMaker = 0.0f;
    const float STAT_STR_Talent_Carpentry = 0.0f,
        STAT_INT_Talent_Carpentry = 0.0f,
        STAT_DEX_Talent_Carpentry = 0.0f,
        STAT_WILL_Talent_Carpentry = 0.0f,
        STAT_LUCK_Talent_Carpentry = 0.0f;
    const float STAT_STR_Talent_Traveler = 0.0f,
        STAT_INT_Talent_Traveler = 0.0f,
        STAT_DEX_Talent_Traveler = 0.0f,
        STAT_WILL_Talent_Traveler = 0.0f,
        STAT_LUCK_Talent_Traveler = 0.0f;
    const float STAT_STR_Talent_Marionette = 0.25f,
        STAT_INT_Talent_Marionette = 0.0f,
        STAT_DEX_Talent_Marionette = 0.25f,
        STAT_WILL_Talent_Marionette = 0.0f,
        STAT_LUCK_Talent_Marionette = 0.0f;
    const float STAT_STR_Talent_Shooter = 0.25f,
        STAT_INT_Talent_Shooter = 0.25f,
        STAT_DEX_Talent_Shooter = 0.0f,
        STAT_WILL_Talent_Shooter = 0.0f,
        STAT_LUCK_Talent_Shooter = 0.0f;
    const float STAT_STR_Talent_Ninja = 0.25f,
        STAT_INT_Talent_Ninja = 0.0f,
        STAT_DEX_Talent_Ninja = 0.0f,
        STAT_WILL_Talent_Ninja = 0.25f,
        STAT_LUCK_Talent_Ninja = 0.0f;
    const float STAT_STR_Talent_ChainBlade = 0.0f,
        STAT_INT_Talent_ChainBlade = 0.25f,
        STAT_DEX_Talent_ChainBlade = 0.0f,
        STAT_WILL_Talent_ChainBlade = 0.0f,
        STAT_LUCK_Talent_ChainBlade = 0.25f;
    const float STAT_STR_Talent_Merlin = 0.0f,
        STAT_INT_Talent_Merlin = 0.5f,
        STAT_DEX_Talent_Merlin = 0.0f,
        STAT_WILL_Talent_Merlin = 0.25f,
        STAT_LUCK_Talent_Merlin = 0.0f;
    const float STAT_STR_Talent_Diva = 0.0f,
        STAT_INT_Talent_Diva = 0.25f,
        STAT_DEX_Talent_Diva = 0.5f,
        STAT_WILL_Talent_Diva = 0.0f,
        STAT_LUCK_Talent_Diva = 0.0f;
    const float STAT_STR_Talent_ProfessorJ = 0.25f,
        STAT_INT_Talent_ProfessorJ = 0.25f,
        STAT_DEX_Talent_ProfessorJ = 0.0f,
        STAT_WILL_Talent_ProfessorJ = 0.0f,
        STAT_LUCK_Talent_ProfessorJ = 0.0f;
    const float STAT_STR_Talent_MasterChef = 0.25f,
        STAT_INT_Talent_MasterChef = 0.0f,
        STAT_DEX_Talent_MasterChef = 0.5f,
        STAT_WILL_Talent_MasterChef = 0.0f,
        STAT_LUCK_Talent_MasterChef = 0.0f;
    const float STAT_STR_Talent_TreasureHunter = 0.0f,
        STAT_INT_Talent_TreasureHunter = 0.25f,
        STAT_DEX_Talent_TreasureHunter = 0.0f,
        STAT_WILL_Talent_TreasureHunter = 0.25f,
        STAT_LUCK_Talent_TreasureHunter = 0.25f;
    const float STAT_STR_Talent_PetHandler = 0.5f,
        STAT_INT_Talent_PetHandler = 0.0f,
        STAT_DEX_Talent_PetHandler = 0.0f,
        STAT_WILL_Talent_PetHandler = 0.25f,
        STAT_LUCK_Talent_PetHandler = 0.25f;
    const float STAT_STR_Talent_MagiGraphy = 0.5f,
        STAT_INT_Talent_MagiGraphy = 0.25f,
        STAT_DEX_Talent_MagiGraphy = 0.25f,
        STAT_WILL_Talent_MagiGraphy = 0.0f,
        STAT_LUCK_Talent_MagiGraphy = 0.0f;

    // 재능 별 보너스 스탯
    // 해당 재능으로 환생하면 자동으로 얻는 스탯입니다.
    // 1회 제공됩니다.
    const float STAT_STR_Talent_Bonus_Combat = 20.0f,
        STAT_INT_Talent_Bonus_Combat = 0.0f,
        STAT_DEX_Talent_Bonus_Combat = 0.0f,
        STAT_WILL_Talent_Bonus_Combat = 0.0f,
        STAT_LUCK_Talent_Bonus_Combat = 0.0f;
    const float STAT_STR_Talent_Bonus_Lance = 15.0f,
        STAT_INT_Talent_Bonus_Lance = 0.0f,
        STAT_DEX_Talent_Bonus_Lance = 0.0f,
        STAT_WILL_Talent_Bonus_Lance = 0.0f,
        STAT_LUCK_Talent_Bonus_Lance = 0.0f;
    const float STAT_STR_Talent_Bonus_RangeCombat = 0.0f,
        STAT_INT_Talent_Bonus_RangeCombat = 0.0f,
        STAT_DEX_Talent_Bonus_RangeCombat = 10.0f,
        STAT_WILL_Talent_Bonus_RangeCombat = 0.0f,
        STAT_LUCK_Talent_Bonus_RangeCombat = 0.0f;
    const float STAT_STR_Talent_Bonus_Mage = 0.0f,
        STAT_INT_Talent_Bonus_Mage = 10.0f,
        STAT_DEX_Talent_Bonus_Mage = 0.0f,
        STAT_WILL_Talent_Bonus_Mage = 0.0f,
        STAT_LUCK_Talent_Bonus_Mage = 0.0f;
    const float STAT_STR_Talent_Bonus_Priest = 0.0f,
        STAT_INT_Talent_Bonus_Priest = 10.0f,
        STAT_DEX_Talent_Bonus_Priest = 0.0f,
        STAT_WILL_Talent_Bonus_Priest = 0.0f,
        STAT_LUCK_Talent_Bonus_Priest = 0.0f;
    const float STAT_STR_Talent_Bonus_Monk = 0.0f,
        STAT_INT_Talent_Bonus_Monk = 0.0f,
        STAT_DEX_Talent_Bonus_Monk = 0.0f,
        STAT_WILL_Talent_Bonus_Monk = 10.0f,
        STAT_LUCK_Talent_Bonus_Monk = 0.0f;
    const float STAT_STR_Talent_Bonus_Bard = 10.0f,
        STAT_INT_Talent_Bonus_Bard = 0.0f,
        STAT_DEX_Talent_Bonus_Bard = 0.0f,
        STAT_WILL_Talent_Bonus_Bard = 0.0f,
        STAT_LUCK_Talent_Bonus_Bard = 0.0f;
    const float STAT_STR_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_INT_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_DEX_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_WILL_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_LUCK_Talent_Bonus_CombatAlchemist = 0.0f;
    const float STAT_STR_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_INT_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_DEX_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_WILL_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_LUCK_Talent_Bonus_TransemuteAlchemist = 0.0f;
    const float STAT_STR_Talent_Bonus_Trader = 0.0f,
        STAT_INT_Talent_Bonus_Trader = 0.0f,
        STAT_DEX_Talent_Bonus_Trader = 0.0f,
        STAT_WILL_Talent_Bonus_Trader = 0.0f,
        STAT_LUCK_Talent_Bonus_Trader = 10.0f;
    const float STAT_STR_Talent_Bonus_Blacksmith = 0.0f,
        STAT_INT_Talent_Bonus_Blacksmith = 0.0f,
        STAT_DEX_Talent_Bonus_Blacksmith = 10.0f,
        STAT_WILL_Talent_Bonus_Blacksmith = 0.0f,
        STAT_LUCK_Talent_Bonus_Blacksmith = 0.0f;
    const float STAT_STR_Talent_Bonus_Cook = 0.0f,
        STAT_INT_Talent_Bonus_Cook = 0.0f,
        STAT_DEX_Talent_Bonus_Cook = 10.0f,
        STAT_WILL_Talent_Bonus_Cook = 0.0f,
        STAT_LUCK_Talent_Bonus_Cook = 0.0f;
    const float STAT_STR_Talent_Bonus_Tailor = 0.0f,
        STAT_INT_Talent_Bonus_Tailor = 0.0f,
        STAT_DEX_Talent_Bonus_Tailor = 10.0f,
        STAT_WILL_Talent_Bonus_Tailor = 0.0f,
        STAT_LUCK_Talent_Bonus_Tailor = 0.0f;
    const float STAT_STR_Talent_Bonus_PotionMaker = 0.0f,
        STAT_INT_Talent_Bonus_PotionMaker = 0.0f,
        STAT_DEX_Talent_Bonus_PotionMaker = 10.0f,
        STAT_WILL_Talent_Bonus_PotionMaker = 0.0f,
        STAT_LUCK_Talent_Bonus_PotionMaker = 0.0f;
    const float STAT_STR_Talent_Bonus_Carpentry = 0.0f,
        STAT_INT_Talent_Bonus_Carpentry = 0.0f,
        STAT_DEX_Talent_Bonus_Carpentry = 0.0f,
        STAT_WILL_Talent_Bonus_Carpentry = 0.0f,
        STAT_LUCK_Talent_Bonus_Carpentry = 0.0f;
    const float STAT_STR_Talent_Bonus_Traveler = 0.0f,
        STAT_INT_Talent_Bonus_Traveler = 0.0f,
        STAT_DEX_Talent_Bonus_Traveler = 0.0f,
        STAT_WILL_Talent_Bonus_Traveler = 10.0f,
        STAT_LUCK_Talent_Bonus_Traveler = 0.0f;
    const float STAT_STR_Talent_Bonus_Marionette = 5.0f,
        STAT_INT_Talent_Bonus_Marionette = 0.0f,
        STAT_DEX_Talent_Bonus_Marionette = 10.0f,
        STAT_WILL_Talent_Bonus_Marionette = 0.0f,
        STAT_LUCK_Talent_Bonus_Marionette = 0.0f;
    const float STAT_STR_Talent_Bonus_Shooter = 5.0f,
        STAT_INT_Talent_Bonus_Shooter = 5.0f,
        STAT_DEX_Talent_Bonus_Shooter = 0.0f,
        STAT_WILL_Talent_Bonus_Shooter = 0.0f,
        STAT_LUCK_Talent_Bonus_Shooter = 0.0f;
    const float STAT_STR_Talent_Bonus_Ninja = 10.0f,
        STAT_INT_Talent_Bonus_Ninja = 0.0f,
        STAT_DEX_Talent_Bonus_Ninja = 0.0f,
        STAT_WILL_Talent_Bonus_Ninja = 10.0f,
        STAT_LUCK_Talent_Bonus_Ninja = 0.0f;
    const float STAT_STR_Talent_Bonus_ChainBlade = 0.0f,
        STAT_INT_Talent_Bonus_ChainBlade = 10.0f,
        STAT_DEX_Talent_Bonus_ChainBlade = 0.0f,
        STAT_WILL_Talent_Bonus_ChainBlade = 0.0f,
        STAT_LUCK_Talent_Bonus_ChainBlade = 10.0f;
    const float STAT_STR_Talent_Bonus_Merlin = 0.0f,
        STAT_INT_Talent_Bonus_Merlin = 10.0f,
        STAT_DEX_Talent_Bonus_Merlin = 0.0f,
        STAT_WILL_Talent_Bonus_Merlin = 5.0f,
        STAT_LUCK_Talent_Bonus_Merlin = 0.0f;
    const float STAT_STR_Talent_Bonus_Diva = 10.0f,
        STAT_INT_Talent_Bonus_Diva = 0.0f,
        STAT_DEX_Talent_Bonus_Diva = 10.0f,
        STAT_WILL_Talent_Bonus_Diva = 0.0f,
        STAT_LUCK_Talent_Bonus_Diva = 0.0f;
    const float STAT_STR_Talent_Bonus_ProfessorJ = 5.0f,
        STAT_INT_Talent_Bonus_ProfessorJ = 10.0f,
        STAT_DEX_Talent_Bonus_ProfessorJ = 0.0f,
        STAT_WILL_Talent_Bonus_ProfessorJ = 0.0f,
        STAT_LUCK_Talent_Bonus_ProfessorJ = 0.0f;
    const float STAT_STR_Talent_Bonus_MasterChef = 5.0f,
        STAT_INT_Talent_Bonus_MasterChef = 0.0f,
        STAT_DEX_Talent_Bonus_MasterChef = 10.0f,
        STAT_WILL_Talent_Bonus_MasterChef = 0.0f,
        STAT_LUCK_Talent_Bonus_MasterChef = 0.0f;
    const float STAT_STR_Talent_Bonus_TreasureHunter = 0.0f,
        STAT_INT_Talent_Bonus_TreasureHunter = 5.0f,
        STAT_DEX_Talent_Bonus_TreasureHunter = 0.0f,
        STAT_WILL_Talent_Bonus_TreasureHunter = 5.0f,
        STAT_LUCK_Talent_Bonus_TreasureHunter = 5.0f;
    const float STAT_STR_Talent_Bonus_PetHandler = 0.0f,
        STAT_INT_Talent_Bonus_PetHandler = 0.0f,
        STAT_DEX_Talent_Bonus_PetHandler = 0.0f,
        STAT_WILL_Talent_Bonus_PetHandler = 10.0f,
        STAT_LUCK_Talent_Bonus_PetHandler = 10.0f;
    const float STAT_STR_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_INT_Talent_Bonus_MagiGraphy = 10.0f,
        STAT_DEX_Talent_Bonus_MagiGraphy = 10.0f,
        STAT_WILL_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_LUCK_Talent_Bonus_MagiGraphy = 0.0f;


    for(int i = AGE::AGE_10; i < AGE::AGE_17 + 1 ; i++) {
        Stats initStats;
        switch(i) {
            case AGE::AGE_10:
                initStats = {STAT_STR_10, STAT_DEX_10, STAT_INT_10, STAT_WILL_10, STAT_LUCK_10};
                break;
            case AGE::AGE_11:
                initStats = {STAT_STR_11, STAT_DEX_11, STAT_INT_11, STAT_WILL_11, STAT_LUCK_11};
                break;
            case AGE::AGE_12:
                initStats = {STAT_STR_12, STAT_DEX_12, STAT_INT_12, STAT_WILL_12, STAT_LUCK_12};
                break;
            case AGE::AGE_13:
                initStats = {STAT_STR_13, STAT_DEX_13, STAT_INT_13, STAT_WILL_13, STAT_LUCK_13};
                break;
            case AGE::AGE_14:
                initStats = {STAT_STR_14, STAT_DEX_14, STAT_INT_14, STAT_WILL_14, STAT_LUCK_14};
                break;
            case AGE::AGE_15:
                initStats = {STAT_STR_15, STAT_DEX_15, STAT_INT_15, STAT_WILL_15, STAT_LUCK_15};
                break;
            case AGE::AGE_16:
                initStats = {STAT_STR_16, STAT_DEX_16, STAT_INT_16, STAT_WILL_16, STAT_LUCK_16};
                break;
            case AGE::AGE_17:
                initStats = {STAT_STR_17, STAT_DEX_17, STAT_INT_17, STAT_WILL_17, STAT_LUCK_17};
                break;
            default:
                break;
        }
        vecStatAge.push_back(initStats);
    }

    for(int i = TALENT::Talent_Combat; i < TALENT::Talent_TreasureHunter + 1 ; i++) {
        Stats initStats;
        switch(i) {
            case Talent_Combat:
                initStats = {STAT_STR_Talent_Combat, STAT_INT_Talent_Combat, STAT_DEX_Talent_Combat, STAT_WILL_Talent_Combat, STAT_LUCK_Talent_Combat};
                break;
            case Talent_Lance:
                initStats = {STAT_STR_Talent_Lance, STAT_INT_Talent_Lance, STAT_DEX_Talent_Lance, STAT_WILL_Talent_Lance, STAT_LUCK_Talent_Lance};
                break;
            case Talent_RangeCombat:
                initStats = {STAT_STR_Talent_RangeCombat, STAT_INT_Talent_RangeCombat, STAT_DEX_Talent_RangeCombat, STAT_WILL_Talent_RangeCombat, STAT_LUCK_Talent_RangeCombat};
                break;
            case Talent_Mage:
                initStats = {STAT_STR_Talent_Mage, STAT_INT_Talent_Mage, STAT_DEX_Talent_Mage, STAT_WILL_Talent_Mage, STAT_LUCK_Talent_Mage};
                break;
            case Talent_Priest:
                initStats = {STAT_STR_Talent_Priest, STAT_INT_Talent_Priest, STAT_DEX_Talent_Priest, STAT_WILL_Talent_Priest, STAT_LUCK_Talent_Priest};
                break;
            case Talent_Monk :
                initStats = {STAT_STR_Talent_Monk, STAT_INT_Talent_Monk, STAT_DEX_Talent_Monk, STAT_WILL_Talent_Monk, STAT_LUCK_Talent_Monk};
                break;
            case Talent_Bard :
                initStats = {STAT_STR_Talent_Bard, STAT_INT_Talent_Bard, STAT_DEX_Talent_Bard, STAT_WILL_Talent_Bard, STAT_LUCK_Talent_Bard};
                break;
            case Talent_CombatAlchemist :
                initStats = {STAT_STR_Talent_CombatAlchemist, STAT_INT_Talent_CombatAlchemist, STAT_DEX_Talent_CombatAlchemist, STAT_WILL_Talent_CombatAlchemist, STAT_LUCK_Talent_CombatAlchemist};
                break;
            case Talent_TransemuteAlchemist :
                initStats = {STAT_STR_Talent_TransemuteAlchemist, STAT_INT_Talent_TransemuteAlchemist, STAT_DEX_Talent_TransemuteAlchemist, STAT_WILL_Talent_TransemuteAlchemist, STAT_LUCK_Talent_TransemuteAlchemist};
                break;
            case Talent_Trader :
                initStats = {STAT_STR_Talent_Trader, STAT_INT_Talent_Trader, STAT_DEX_Talent_Trader, STAT_WILL_Talent_Trader, STAT_LUCK_Talent_Trader};
                break;
            case Talent_Blacksmith :
                initStats = {STAT_STR_Talent_Blacksmith, STAT_INT_Talent_Blacksmith, STAT_DEX_Talent_Blacksmith, STAT_WILL_Talent_Blacksmith, STAT_LUCK_Talent_Blacksmith};
                break;
            case Talent_Cook :
                initStats = {STAT_STR_Talent_Cook, STAT_INT_Talent_Cook, STAT_DEX_Talent_Cook, STAT_WILL_Talent_Cook, STAT_LUCK_Talent_Cook};
                break;
            case Talent_Tailor :
                initStats = {STAT_STR_Talent_Tailor, STAT_INT_Talent_Tailor, STAT_DEX_Talent_Tailor, STAT_WILL_Talent_Tailor, STAT_LUCK_Talent_Tailor};
                break;
            case Talent_PotionMaker :
                initStats = {STAT_STR_Talent_PotionMaker, STAT_INT_Talent_PotionMaker, STAT_DEX_Talent_PotionMaker, STAT_WILL_Talent_PotionMaker, STAT_LUCK_Talent_PotionMaker};
                break;
            case Talent_Carpentry :
                initStats = {STAT_STR_Talent_Carpentry, STAT_INT_Talent_Carpentry, STAT_DEX_Talent_Carpentry, STAT_WILL_Talent_Carpentry, STAT_LUCK_Talent_Carpentry};
                break;
            case Talent_Traveler :
                initStats = {STAT_STR_Talent_Traveler, STAT_INT_Talent_Traveler, STAT_DEX_Talent_Traveler, STAT_WILL_Talent_Traveler, STAT_LUCK_Talent_Traveler};
                break;
            case Talent_Marionette :
                initStats = {STAT_STR_Talent_Marionette, STAT_INT_Talent_Marionette, STAT_DEX_Talent_Marionette, STAT_WILL_Talent_Marionette, STAT_LUCK_Talent_Marionette};
                break;
            case Talent_Shooter :
                initStats = {STAT_STR_Talent_Shooter, STAT_INT_Talent_Shooter, STAT_DEX_Talent_Shooter, STAT_WILL_Talent_Shooter, STAT_LUCK_Talent_Shooter};
                break;
            case Talent_Ninja :
                initStats = {STAT_STR_Talent_Ninja, STAT_INT_Talent_Ninja, STAT_DEX_Talent_Ninja, STAT_WILL_Talent_Ninja, STAT_LUCK_Talent_Ninja};
                break;
            case Talent_ChainBlade :
                initStats = {STAT_STR_Talent_ChainBlade, STAT_INT_Talent_ChainBlade, STAT_DEX_Talent_ChainBlade, STAT_WILL_Talent_ChainBlade, STAT_LUCK_Talent_ChainBlade};
                break;
            case Talent_Merlin :
                initStats = {STAT_STR_Talent_Merlin, STAT_INT_Talent_Merlin, STAT_DEX_Talent_Merlin, STAT_WILL_Talent_Merlin, STAT_LUCK_Talent_Merlin};
                break;
            case Talent_Diva :
                initStats = {STAT_STR_Talent_Diva, STAT_INT_Talent_Diva, STAT_DEX_Talent_Diva, STAT_WILL_Talent_Diva, STAT_LUCK_Talent_Diva};
                break;
            case Talent_ProfessorJ :
                initStats = {STAT_STR_Talent_ProfessorJ, STAT_INT_Talent_ProfessorJ, STAT_DEX_Talent_ProfessorJ, STAT_WILL_Talent_ProfessorJ, STAT_LUCK_Talent_ProfessorJ};
                break;
            case Talent_MasterChef :
                initStats = {STAT_STR_Talent_MasterChef, STAT_INT_Talent_MasterChef, STAT_DEX_Talent_MasterChef, STAT_WILL_Talent_MasterChef, STAT_LUCK_Talent_MasterChef};
                break;
            case Talent_TreasureHunter:
                initStats = {STAT_STR_Talent_TreasureHunter, STAT_INT_Talent_TreasureHunter, STAT_DEX_Talent_TreasureHunter, STAT_WILL_Talent_TreasureHunter, STAT_LUCK_Talent_TreasureHunter};
                break;
            case Talent_PetHandler:
                initStats = {STAT_STR_Talent_PetHandler, STAT_INT_Talent_PetHandler, STAT_DEX_Talent_PetHandler, STAT_WILL_Talent_PetHandler, STAT_LUCK_Talent_PetHandler};
                break;
            case Talent_MagiGraphy:
                initStats = {STAT_STR_Talent_MagiGraphy, STAT_INT_Talent_MagiGraphy, STAT_DEX_Talent_MagiGraphy, STAT_WILL_Talent_MagiGraphy, STAT_LUCK_Talent_MagiGraphy};
                break;
            default:
                break;
        }
        vecStatTalent.push_back(initStats);
    }

    for(int i = TALENT::Talent_Combat; i < TALENT::Talent_TreasureHunter + 1 ; i++) {
        Stats initStats;
        switch(i) {
            case Talent_Bonus_Combat:
                initStats = {STAT_STR_Talent_Bonus_Combat, STAT_INT_Talent_Bonus_Combat, STAT_DEX_Talent_Bonus_Combat, STAT_WILL_Talent_Bonus_Combat, STAT_LUCK_Talent_Bonus_Combat};
                break;
            case Talent_Bonus_Lance:
                initStats = {STAT_STR_Talent_Bonus_Lance, STAT_INT_Talent_Bonus_Lance, STAT_DEX_Talent_Bonus_Lance, STAT_WILL_Talent_Bonus_Lance, STAT_LUCK_Talent_Bonus_Lance};
                break;
            case Talent_Bonus_RangeCombat:
                initStats = {STAT_STR_Talent_Bonus_RangeCombat, STAT_INT_Talent_Bonus_RangeCombat, STAT_DEX_Talent_Bonus_RangeCombat, STAT_WILL_Talent_Bonus_RangeCombat, STAT_LUCK_Talent_Bonus_RangeCombat};
                break;
            case Talent_Bonus_Mage:
                initStats = {STAT_STR_Talent_Bonus_Mage, STAT_INT_Talent_Bonus_Mage, STAT_DEX_Talent_Bonus_Mage, STAT_WILL_Talent_Bonus_Mage, STAT_LUCK_Talent_Bonus_Mage};
                break;
            case Talent_Bonus_Priest:
                initStats = {STAT_STR_Talent_Bonus_Priest, STAT_INT_Talent_Bonus_Priest, STAT_DEX_Talent_Bonus_Priest, STAT_WILL_Talent_Bonus_Priest, STAT_LUCK_Talent_Bonus_Priest};
                break;
            case Talent_Bonus_Monk :
                initStats = {STAT_STR_Talent_Bonus_Monk, STAT_INT_Talent_Bonus_Monk, STAT_DEX_Talent_Bonus_Monk, STAT_WILL_Talent_Bonus_Monk, STAT_LUCK_Talent_Bonus_Monk};
                break;
            case Talent_Bonus_Bard :
                initStats = {STAT_STR_Talent_Bonus_Bard, STAT_INT_Talent_Bonus_Bard, STAT_DEX_Talent_Bonus_Bard, STAT_WILL_Talent_Bonus_Bard, STAT_LUCK_Talent_Bonus_Bard};
                break;
            case Talent_Bonus_CombatAlchemist :
                initStats = {STAT_STR_Talent_Bonus_CombatAlchemist, STAT_INT_Talent_Bonus_CombatAlchemist, STAT_DEX_Talent_Bonus_CombatAlchemist, STAT_WILL_Talent_Bonus_CombatAlchemist, STAT_LUCK_Talent_Bonus_CombatAlchemist};
                break;
            case Talent_Bonus_TransemuteAlchemist :
                initStats = {STAT_STR_Talent_Bonus_TransemuteAlchemist, STAT_INT_Talent_Bonus_TransemuteAlchemist, STAT_DEX_Talent_Bonus_TransemuteAlchemist, STAT_WILL_Talent_Bonus_TransemuteAlchemist, STAT_LUCK_Talent_Bonus_TransemuteAlchemist};
                break;
            case Talent_Bonus_Trader :
                initStats = {STAT_STR_Talent_Bonus_Trader, STAT_INT_Talent_Bonus_Trader, STAT_DEX_Talent_Bonus_Trader, STAT_WILL_Talent_Bonus_Trader, STAT_LUCK_Talent_Bonus_Trader};
                break;
            case Talent_Bonus_Blacksmith :
                initStats = {STAT_STR_Talent_Bonus_Blacksmith, STAT_INT_Talent_Bonus_Blacksmith, STAT_DEX_Talent_Bonus_Blacksmith, STAT_WILL_Talent_Bonus_Blacksmith, STAT_LUCK_Talent_Bonus_Blacksmith};
                break;
            case Talent_Bonus_Cook :
                initStats = {STAT_STR_Talent_Bonus_Cook, STAT_INT_Talent_Bonus_Cook, STAT_DEX_Talent_Bonus_Cook, STAT_WILL_Talent_Bonus_Cook, STAT_LUCK_Talent_Bonus_Cook};
                break;
            case Talent_Bonus_Tailor :
                initStats = {STAT_STR_Talent_Bonus_Tailor, STAT_INT_Talent_Bonus_Tailor, STAT_DEX_Talent_Bonus_Tailor, STAT_WILL_Talent_Bonus_Tailor, STAT_LUCK_Talent_Bonus_Tailor};
                break;
            case Talent_Bonus_PotionMaker :
                initStats = {STAT_STR_Talent_Bonus_PotionMaker, STAT_INT_Talent_Bonus_PotionMaker, STAT_DEX_Talent_Bonus_PotionMaker, STAT_WILL_Talent_Bonus_PotionMaker, STAT_LUCK_Talent_Bonus_PotionMaker};
                break;
            case Talent_Bonus_Carpentry :
                initStats = {STAT_STR_Talent_Bonus_Carpentry, STAT_INT_Talent_Bonus_Carpentry, STAT_DEX_Talent_Bonus_Carpentry, STAT_WILL_Talent_Bonus_Carpentry, STAT_LUCK_Talent_Bonus_Carpentry};
                break;
            case Talent_Bonus_Traveler :
                initStats = {STAT_STR_Talent_Bonus_Traveler, STAT_INT_Talent_Bonus_Traveler, STAT_DEX_Talent_Bonus_Traveler, STAT_WILL_Talent_Bonus_Traveler, STAT_LUCK_Talent_Bonus_Traveler};
                break;
            case Talent_Bonus_Marionette :
                initStats = {STAT_STR_Talent_Bonus_Marionette, STAT_INT_Talent_Bonus_Marionette, STAT_DEX_Talent_Bonus_Marionette, STAT_WILL_Talent_Bonus_Marionette, STAT_LUCK_Talent_Bonus_Marionette};
                break;
            case Talent_Bonus_Shooter :
                initStats = {STAT_STR_Talent_Bonus_Shooter, STAT_INT_Talent_Bonus_Shooter, STAT_DEX_Talent_Bonus_Shooter, STAT_WILL_Talent_Bonus_Shooter, STAT_LUCK_Talent_Bonus_Shooter};
                break;
            case Talent_Bonus_Ninja :
                initStats = {STAT_STR_Talent_Bonus_Ninja, STAT_INT_Talent_Bonus_Ninja, STAT_DEX_Talent_Bonus_Ninja, STAT_WILL_Talent_Bonus_Ninja, STAT_LUCK_Talent_Bonus_Ninja};
                break;
            case Talent_Bonus_ChainBlade :
                initStats = {STAT_STR_Talent_Bonus_ChainBlade, STAT_INT_Talent_Bonus_ChainBlade, STAT_DEX_Talent_Bonus_ChainBlade, STAT_WILL_Talent_Bonus_ChainBlade, STAT_LUCK_Talent_Bonus_ChainBlade};
                break;
            case Talent_Bonus_Merlin :
                initStats = {STAT_STR_Talent_Bonus_Merlin, STAT_INT_Talent_Bonus_Merlin, STAT_DEX_Talent_Bonus_Merlin, STAT_WILL_Talent_Bonus_Merlin, STAT_LUCK_Talent_Bonus_Merlin};
                break;
            case Talent_Bonus_Diva :
                initStats = {STAT_STR_Talent_Bonus_Diva, STAT_INT_Talent_Bonus_Diva, STAT_DEX_Talent_Bonus_Diva, STAT_WILL_Talent_Bonus_Diva, STAT_LUCK_Talent_Bonus_Diva};
                break;
            case Talent_Bonus_ProfessorJ :
                initStats = {STAT_STR_Talent_Bonus_ProfessorJ, STAT_INT_Talent_Bonus_ProfessorJ, STAT_DEX_Talent_Bonus_ProfessorJ, STAT_WILL_Talent_Bonus_ProfessorJ, STAT_LUCK_Talent_Bonus_ProfessorJ};
                break;
            case Talent_Bonus_MasterChef :
                initStats = {STAT_STR_Talent_Bonus_MasterChef, STAT_INT_Talent_Bonus_MasterChef, STAT_DEX_Talent_Bonus_MasterChef, STAT_WILL_Talent_Bonus_MasterChef, STAT_LUCK_Talent_Bonus_MasterChef};
                break;
            case Talent_Bonus_TreasureHunter:
                initStats = {STAT_STR_Talent_Bonus_TreasureHunter, STAT_INT_Talent_Bonus_TreasureHunter, STAT_DEX_Talent_Bonus_TreasureHunter, STAT_WILL_Talent_Bonus_TreasureHunter, STAT_LUCK_Talent_Bonus_TreasureHunter};
                break;
            case Talent_Bonus_PetHandler:
                initStats = {STAT_STR_Talent_Bonus_PetHandler, STAT_INT_Talent_Bonus_PetHandler, STAT_DEX_Talent_Bonus_PetHandler, STAT_WILL_Talent_Bonus_PetHandler, STAT_LUCK_Talent_Bonus_PetHandler};
                break;
            case Talent_Bonus_MagiGraphy:
                initStats = {STAT_STR_Talent_Bonus_MagiGraphy, STAT_INT_Talent_Bonus_MagiGraphy, STAT_DEX_Talent_Bonus_MagiGraphy, STAT_WILL_Talent_Bonus_MagiGraphy, STAT_LUCK_Talent_Bonus_MagiGraphy};
                break;
            default:
                break;
        }
        vecStatTalentBonus.push_back(initStats);
    }
}
