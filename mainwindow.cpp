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
    ui->comboAge->addItem("18");
    ui->comboAge->addItem("19");
    ui->comboAge->addItem("20");
    ui->comboAge->addItem("21");
    ui->comboAge->addItem("22");
    ui->comboAge->addItem("23");
    ui->comboAge->addItem("24");
    ui->comboAge->addItem("25이상");

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
    ui->comboTalent->addItem("프로페서 J");
    ui->comboTalent->addItem("마스터셰프");
    ui->comboTalent->addItem("트래저 헌터");

    InitializeStats();

    connect(ui->btnCalculate,SIGNAL(clicked()),this,SLOT(CalculateStats()));

}
void MainWindow::CalculateStats()
{
    int currentLife = ui->leLife->text().toInt();
    int currentMana = ui->leMana->text().toInt();
    int currentStam = ui->leStam->text().toInt();
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
    currentStats.statLife = currentLife + (vecStatAge.at(currentAge).statLife * currentCombatLevel) + (vecStatAge.at(currentAge).statLife * currentExplorerLevel) +
                            (vecStatTalent.at(currentTalent).statLife * currentCombatLevel) + (vecStatTalent.at(currentTalent).statLife * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statLife;
    currentStats.statMana = currentMana + (vecStatAge.at(currentAge).statMana * currentCombatLevel) + (vecStatAge.at(currentAge).statMana * currentExplorerLevel) +
                            (vecStatTalent.at(currentTalent).statMana * currentCombatLevel) + (vecStatTalent.at(currentTalent).statMana * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statMana;
    currentStats.statStam = currentStam + (vecStatAge.at(currentAge).statStam * currentCombatLevel) + (vecStatAge.at(currentAge).statStam * currentExplorerLevel) +
                            (vecStatTalent.at(currentTalent).statStam * currentCombatLevel) + (vecStatTalent.at(currentTalent).statStam * currentExplorerLevel) + vecStatTalentBonus.at(currentTalentBonus).statStam;
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

    ui->lblLife->setText(QString("%1").arg(currentStats.statLife));
    ui->lblMana->setText(QString("%1").arg(currentStats.statMana));
    ui->lblStam->setText(QString("%1").arg(currentStats.statStam));
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
    const float STAT_LIFE_10 = 1.0f, STAT_MANA_10 = 0.25f, STAT_STAM_10 = 0.5f, STAT_STR_10 = 0.5f, STAT_INT_10 = 0.0f, STAT_DEX_10 = 0.5f, STAT_WILL_10 = 0.75f, STAT_LUCK_10 = 0.75f;
    const float STAT_LIFE_11 = 1.0f, STAT_MANA_11 = 0.25f, STAT_STAM_11 = 0.5f, STAT_STR_11 = 0.5f, STAT_INT_11 = 0.0f, STAT_DEX_11 = 0.75f, STAT_WILL_11 = 0.75f, STAT_LUCK_11 = 0.5f;
    const float STAT_LIFE_12 = 0.75f, STAT_MANA_12 = 0.25f, STAT_STAM_12 = 0.75f, STAT_STR_12 = 0.5f, STAT_INT_12 = 0.0f, STAT_DEX_12 = 0.75f, STAT_WILL_12 = 0.75f, STAT_LUCK_12 = 0.5f;
    const float STAT_LIFE_13 = 0.75f, STAT_MANA_13 = 0.5f, STAT_STAM_13 = 0.75f, STAT_STR_13 = 0.5f, STAT_INT_13 = 0.0f, STAT_DEX_13 = 0.75f, STAT_WILL_13 = 0.75f, STAT_LUCK_13 = 0.25f;
    const float STAT_LIFE_14 = 0.75f, STAT_MANA_14 = 0.5f, STAT_STAM_14 = 0.75f, STAT_STR_14 = 0.5f, STAT_INT_14 = 0.25f, STAT_DEX_14 = 0.5f, STAT_WILL_14 = 0.5f, STAT_LUCK_14 = 0.25f;
    const float STAT_LIFE_15 = 0.75f, STAT_MANA_15 = 0.5f, STAT_STAM_15 = 0.75f, STAT_STR_15 = 0.5f, STAT_INT_15 = 0.5f, STAT_DEX_15 = 0.25f, STAT_WILL_15 = 0.5f, STAT_LUCK_15 = 0.0f;
    const float STAT_LIFE_16 = 0.5f, STAT_MANA_16 = 0.75f, STAT_STAM_16 = 0.75f, STAT_STR_16 = 0.5f, STAT_INT_16 = 0.5f, STAT_DEX_16 = 0.25f, STAT_WILL_16 = 0.5f, STAT_LUCK_16 = 0.0f;
    const float STAT_LIFE_17 = 0.5f, STAT_MANA_17 = 0.75f, STAT_STAM_17 = 0.75f, STAT_STR_17 = 0.5f, STAT_INT_17 = 0.75f, STAT_DEX_17 = 0.0f, STAT_WILL_17 = 0.25f, STAT_LUCK_17 = 0.0f;
    const float STAT_LIFE_18 = 0.5f, STAT_MANA_18 = 0.75f, STAT_STAM_18 = 0.75f, STAT_STR_18 = 0.5f, STAT_INT_18 = 0.75f, STAT_DEX_18 = 0.0f, STAT_WILL_18 = 0.25f, STAT_LUCK_18 = 0.0f;
    const float STAT_LIFE_19 = 0.5f, STAT_MANA_19 = 0.75f, STAT_STAM_19 = 0.75f, STAT_STR_19 = 0.5f, STAT_INT_19 = 0.75f, STAT_DEX_19 = 0.0f, STAT_WILL_19 = 0.25f, STAT_LUCK_19 = 0.0f;
    const float STAT_LIFE_20 = 0.25f, STAT_MANA_20 = 0.75f, STAT_STAM_20 = 0.75f, STAT_STR_20 = 0.5f, STAT_INT_20 = 0.75f, STAT_DEX_20 = 0.25f, STAT_WILL_20 = 0.25f, STAT_LUCK_20 = 0.0f;
    const float STAT_LIFE_21 = 0.25f, STAT_MANA_21 = 0.5f, STAT_STAM_21 = 0.5f, STAT_STR_21 = 0.5f, STAT_INT_21 = 1.0f, STAT_DEX_21 = 0.5f, STAT_WILL_21 = 0.25f, STAT_LUCK_21 = 0.0f;
    const float STAT_LIFE_22 = 0.25f, STAT_MANA_22 = 0.5f, STAT_STAM_22 = 0.25f, STAT_STR_22 = 0.25f, STAT_INT_22 = 0.75f, STAT_DEX_22 = 0.75f, STAT_WILL_22 = 0.25f, STAT_LUCK_22 = 0.0f;
    const float STAT_LIFE_23 = 0.25f, STAT_MANA_23 = 0.25f, STAT_STAM_23 = 0.25f, STAT_STR_23 = 0.25f, STAT_INT_23 = 0.5f, STAT_DEX_23 = 0.5f, STAT_WILL_23 = 0.25f, STAT_LUCK_23 = 0.0f;
    const float STAT_LIFE_24 = 0.0f, STAT_MANA_24 = 0.25f, STAT_STAM_24 = 0.25f, STAT_STR_24 = 0.25f, STAT_INT_24 = 0.25f, STAT_DEX_24 = 0.25f, STAT_WILL_24 = 0.25f, STAT_LUCK_24 = 0.0f;
    const float STAT_LIFE_25_OVER = 0.0f, STAT_MANA_25_OVER = 0.0f, STAT_STAM_25_OVER = 0.0f, STAT_STR_25_OVER = 0.0f, STAT_INT_25_OVER = 0.0f, STAT_DEX_25_OVER = 0.0f, STAT_WILL_25_OVER = 0.0f, STAT_LUCK_25_OVER = 0.0f;

    // 재능 별 레벨업 시 얻는 스탯
    // 재능에 따라 레벨 업 할 때마다 아래의 스탯을 추가로 얻습니다.
    // 표기는 소수점을 가립니다.
    const float STAT_LIFE_Talent_Combat = 0.0f,
        STAT_MANA_Talent_Combat = 0.0f,
        STAT_STAM_Talent_Combat = 0.0f,
        STAT_STR_Talent_Combat = 0.5f,
        STAT_INT_Talent_Combat = 0.0f,
        STAT_DEX_Talent_Combat = 0.0f,
        STAT_WILL_Talent_Combat = 0.0f,
        STAT_LUCK_Talent_Combat = 0.0f;
    const float STAT_LIFE_Talent_Lance = 0.0f,
        STAT_MANA_Talent_Lance = 0.0f,
        STAT_STAM_Talent_Lance = 0.0f,
        STAT_STR_Talent_Lance = 0.5f,
        STAT_INT_Talent_Lance = 0.0f,
        STAT_DEX_Talent_Lance = 0.0f,
        STAT_WILL_Talent_Lance = 0.0f,
        STAT_LUCK_Talent_Lance = 0.0f;
    const float STAT_LIFE_Talent_RangeCombat = 0.0f,
        STAT_MANA_Talent_RangeCombat = 0.0f,
        STAT_STAM_Talent_RangeCombat = 0.0f,
        STAT_STR_Talent_RangeCombat = 0.0f,
        STAT_INT_Talent_RangeCombat = 0.0f,
        STAT_DEX_Talent_RangeCombat = 0.5f,
        STAT_WILL_Talent_RangeCombat = 0.0f,
        STAT_LUCK_Talent_RangeCombat = 0.0f;
    const float STAT_LIFE_Talent_Mage = 0.0f,
        STAT_MANA_Talent_Mage = 0.0f,
        STAT_STAM_Talent_Mage = 0.0f,
        STAT_STR_Talent_Mage = 0.0f,
        STAT_INT_Talent_Mage = 0.5f,
        STAT_DEX_Talent_Mage = 0.0f,
        STAT_WILL_Talent_Mage = 0.0f,
        STAT_LUCK_Talent_Mage = 0.0f;
    const float STAT_LIFE_Talent_Priest = 0.0f,
        STAT_MANA_Talent_Priest = 0.0f,
        STAT_STAM_Talent_Priest = 0.0f,
        STAT_STR_Talent_Priest = 0.0f,
        STAT_INT_Talent_Priest = 0.5f,
        STAT_DEX_Talent_Priest = 0.0f,
        STAT_WILL_Talent_Priest = 0.0f,
        STAT_LUCK_Talent_Priest = 0.0f;
    const float STAT_LIFE_Talent_Monk = 0.0f,
        STAT_MANA_Talent_Monk = 0.0f,
        STAT_STAM_Talent_Monk = 0.0f,
        STAT_STR_Talent_Monk = 0.0f,
        STAT_INT_Talent_Monk = 0.0f,
        STAT_DEX_Talent_Monk = 0.0f,
        STAT_WILL_Talent_Monk = 0.5f,
        STAT_LUCK_Talent_Monk = 0.0f;
    const float STAT_LIFE_Talent_Bard = 0.25f,
        STAT_MANA_Talent_Bard = 0.0f,
        STAT_STAM_Talent_Bard = 0.25f,
        STAT_STR_Talent_Bard = 0.0f,
        STAT_INT_Talent_Bard = 0.0f,
        STAT_DEX_Talent_Bard = 0.0f,
        STAT_WILL_Talent_Bard = 0.0f,
        STAT_LUCK_Talent_Bard = 0.0f;
    const float STAT_LIFE_Talent_CombatAlchemist = 0.0f,
        STAT_MANA_Talent_CombatAlchemist = 0.5f,
        STAT_STAM_Talent_CombatAlchemist = 0.5f,
        STAT_STR_Talent_CombatAlchemist = 0.0f,
        STAT_INT_Talent_CombatAlchemist = 0.0f,
        STAT_DEX_Talent_CombatAlchemist = 0.0f,
        STAT_WILL_Talent_CombatAlchemist = 0.0f,
        STAT_LUCK_Talent_CombatAlchemist = 0.0f;
    const float STAT_LIFE_Talent_TransemuteAlchemist = 0.0f,
        STAT_MANA_Talent_TransemuteAlchemist = 0.5f,
        STAT_STAM_Talent_TransemuteAlchemist = 0.5f,
        STAT_STR_Talent_TransemuteAlchemist = 0.0f,
        STAT_INT_Talent_TransemuteAlchemist = 0.0f,
        STAT_DEX_Talent_TransemuteAlchemist = 0.0f,
        STAT_WILL_Talent_TransemuteAlchemist = 0.0f,
        STAT_LUCK_Talent_TransemuteAlchemist = 0.0f;
    const float STAT_LIFE_Talent_Trader = 0.0f,
        STAT_MANA_Talent_Trader = 0.0f,
        STAT_STAM_Talent_Trader = 0.0f,
        STAT_STR_Talent_Trader = 0.0f,
        STAT_INT_Talent_Trader = 0.0f,
        STAT_DEX_Talent_Trader = 0.0f,
        STAT_WILL_Talent_Trader = 0.0f,
        STAT_LUCK_Talent_Trader = 0.5f;
    const float STAT_LIFE_Talent_Blacksmith = 0.0f,
        STAT_MANA_Talent_Blacksmith = 0.0f,
        STAT_STAM_Talent_Blacksmith = 0.25f,
        STAT_STR_Talent_Blacksmith = 0.0f,
        STAT_INT_Talent_Blacksmith = 0.0f,
        STAT_DEX_Talent_Blacksmith = 0.25f,
        STAT_WILL_Talent_Blacksmith = 0.0f,
        STAT_LUCK_Talent_Blacksmith = 0.0f;
    const float STAT_LIFE_Talent_Cook = 0.0f,
        STAT_MANA_Talent_Cook = 0.0f,
        STAT_STAM_Talent_Cook = 0.25f,
        STAT_STR_Talent_Cook = 0.0f,
        STAT_INT_Talent_Cook = 0.0f,
        STAT_DEX_Talent_Cook = 0.25f,
        STAT_WILL_Talent_Cook = 0.0f,
        STAT_LUCK_Talent_Cook = 0.0f;
    const float STAT_LIFE_Talent_Tailor = 0.0f,
        STAT_MANA_Talent_Tailor = 0.0f,
        STAT_STAM_Talent_Tailor = 0.25f,
        STAT_STR_Talent_Tailor = 0.0f,
        STAT_INT_Talent_Tailor = 0.0f,
        STAT_DEX_Talent_Tailor = 0.25f,
        STAT_WILL_Talent_Tailor = 0.0f,
        STAT_LUCK_Talent_Tailor = 0.0f;
    const float STAT_LIFE_Talent_PotionMaker = 0.0f,
        STAT_MANA_Talent_PotionMaker = 0.25f,
        STAT_STAM_Talent_PotionMaker = 0.25f,
        STAT_STR_Talent_PotionMaker = 0.0f,
        STAT_INT_Talent_PotionMaker = 0.0f,
        STAT_DEX_Talent_PotionMaker = 0.0f,
        STAT_WILL_Talent_PotionMaker = 0.0f,
        STAT_LUCK_Talent_PotionMaker = 0.0f;
    const float STAT_LIFE_Talent_Carpentry = 0.0f,
        STAT_MANA_Talent_Carpentry = 0.0f,
        STAT_STAM_Talent_Carpentry = 0.5f,
        STAT_STR_Talent_Carpentry = 0.0f,
        STAT_INT_Talent_Carpentry = 0.0f,
        STAT_DEX_Talent_Carpentry = 0.0f,
        STAT_WILL_Talent_Carpentry = 0.0f,
        STAT_LUCK_Talent_Carpentry = 0.0f;
    const float STAT_LIFE_Talent_Traveler = 0.25f,
        STAT_MANA_Talent_Traveler = 0.0f,
        STAT_STAM_Talent_Traveler = 0.25f,
        STAT_STR_Talent_Traveler = 0.0f,
        STAT_INT_Talent_Traveler = 0.0f,
        STAT_DEX_Talent_Traveler = 0.0f,
        STAT_WILL_Talent_Traveler = 0.0f,
        STAT_LUCK_Talent_Traveler = 0.0f;
    const float STAT_LIFE_Talent_Marionette = 0.0f,
        STAT_MANA_Talent_Marionette = 0.0f,
        STAT_STAM_Talent_Marionette = 0.25f,
        STAT_STR_Talent_Marionette = 0.25f,
        STAT_INT_Talent_Marionette = 0.0f,
        STAT_DEX_Talent_Marionette = 0.25f,
        STAT_WILL_Talent_Marionette = 0.0f,
        STAT_LUCK_Talent_Marionette = 0.0f;
    const float STAT_LIFE_Talent_Shooter = 0.0f,
        STAT_MANA_Talent_Shooter = 0.0f,
        STAT_STAM_Talent_Shooter = 0.0f,
        STAT_STR_Talent_Shooter = 0.25f,
        STAT_INT_Talent_Shooter = 0.25f,
        STAT_DEX_Talent_Shooter = 0.0f,
        STAT_WILL_Talent_Shooter = 0.0f,
        STAT_LUCK_Talent_Shooter = 0.0f;
    const float STAT_LIFE_Talent_Ninja = 0.0f,
        STAT_MANA_Talent_Ninja = 0.0f,
        STAT_STAM_Talent_Ninja = 0.0f,
        STAT_STR_Talent_Ninja = 0.25f,
        STAT_INT_Talent_Ninja = 0.0f,
        STAT_DEX_Talent_Ninja = 0.0f,
        STAT_WILL_Talent_Ninja = 0.25f,
        STAT_LUCK_Talent_Ninja = 0.0f;
    const float STAT_LIFE_Talent_ChainBlade = 0.0f,
        STAT_MANA_Talent_ChainBlade = 0.0f,
        STAT_STAM_Talent_ChainBlade = 0.0f,
        STAT_STR_Talent_ChainBlade = 0.0f,
        STAT_INT_Talent_ChainBlade = 0.0f,
        STAT_DEX_Talent_ChainBlade = 0.25f,
        STAT_WILL_Talent_ChainBlade = 0.0f,
        STAT_LUCK_Talent_ChainBlade = 0.25f;
    const float STAT_LIFE_Talent_Merlin = 0.0f,
        STAT_MANA_Talent_Merlin = 0.25f,
        STAT_STAM_Talent_Merlin = 0.0f,
        STAT_STR_Talent_Merlin = 0.0f,
        STAT_INT_Talent_Merlin = 0.5f,
        STAT_DEX_Talent_Merlin = 0.0f,
        STAT_WILL_Talent_Merlin = 0.25f,
        STAT_LUCK_Talent_Merlin = 0.0f;
    const float STAT_LIFE_Talent_Diva = 0.0f,
        STAT_MANA_Talent_Diva = 0.0f,
        STAT_STAM_Talent_Diva = 0.25f,
        STAT_STR_Talent_Diva = 0.0f,
        STAT_INT_Talent_Diva = 0.25f,
        STAT_DEX_Talent_Diva = 0.5f,
        STAT_WILL_Talent_Diva = 0.0f,
        STAT_LUCK_Talent_Diva = 0.0f;
    const float STAT_LIFE_Talent_ProfessorJ = 0.25f,
        STAT_MANA_Talent_ProfessorJ = 0.25f,
        STAT_STAM_Talent_ProfessorJ = 0.25f,
        STAT_STR_Talent_ProfessorJ = 0.25f,
        STAT_INT_Talent_ProfessorJ = 0.25f,
        STAT_DEX_Talent_ProfessorJ = 0.0f,
        STAT_WILL_Talent_ProfessorJ = 0.0f,
        STAT_LUCK_Talent_ProfessorJ = 0.0f;
    const float STAT_LIFE_Talent_MasterChef = 0.25f,
        STAT_MANA_Talent_MasterChef = 0.25f,
        STAT_STAM_Talent_MasterChef = 0.25f,
        STAT_STR_Talent_MasterChef = 0.25f,
        STAT_INT_Talent_MasterChef = 0.0f,
        STAT_DEX_Talent_MasterChef = 0.5f,
        STAT_WILL_Talent_MasterChef = 0.0f,
        STAT_LUCK_Talent_MasterChef = 0.0f;
    const float STAT_LIFE_Talent_TreasureHunter = 0.0f,
        STAT_MANA_Talent_TreasureHunter = 0.0f,
        STAT_STAM_Talent_TreasureHunter = 0.25f,
        STAT_STR_Talent_TreasureHunter = 0.0f,
        STAT_INT_Talent_TreasureHunter = 0.25f,
        STAT_DEX_Talent_TreasureHunter = 0.0f,
        STAT_WILL_Talent_TreasureHunter = 0.25f,
        STAT_LUCK_Talent_TreasureHunter = 0.25f;
    const float STAT_LIFE_Talent_PetHandler = 0.0f,
        STAT_MANA_Talent_PetHandler = 0.0f,
        STAT_STAM_Talent_PetHandler = 0.0f,
        STAT_STR_Talent_PetHandler = 0.0f,
        STAT_INT_Talent_PetHandler = 0.0f,
        STAT_DEX_Talent_PetHandler = 0.0f,
        STAT_WILL_Talent_PetHandler = 0.25f,
        STAT_LUCK_Talent_PetHandler = 0.25f;
    const float STAT_LIFE_Talent_MagiGraphy = 0.0f,
        STAT_MANA_Talent_MagiGraphy = 0.0f,
        STAT_STAM_Talent_MagiGraphy = 0.0f,
        STAT_STR_Talent_MagiGraphy = 0.0f,
        STAT_INT_Talent_MagiGraphy = 0.25f,
        STAT_DEX_Talent_MagiGraphy = 0.25f,
        STAT_WILL_Talent_MagiGraphy = 0.0f,
        STAT_LUCK_Talent_MagiGraphy = 0.0f;

    // 재능 별 보너스 스탯
    // 해당 재능으로 환생하면 자동으로 얻는 스탯입니다.
    // 1회 제공됩니다.
    const float STAT_LIFE_Talent_Bonus_Combat = 0.0f,
        STAT_MANA_Talent_Bonus_Combat = 0.0f,
        STAT_STAM_Talent_Bonus_Combat = 0.0f,
        STAT_STR_Talent_Bonus_Combat = 20.0f,
        STAT_INT_Talent_Bonus_Combat = 0.0f,
        STAT_DEX_Talent_Bonus_Combat = 0.0f,
        STAT_WILL_Talent_Bonus_Combat = 0.0f,
        STAT_LUCK_Talent_Bonus_Combat = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Lance = 5.0f,
        STAT_MANA_Talent_Bonus_Lance = 0.0f,
        STAT_STAM_Talent_Bonus_Lance = 0.0f,
        STAT_STR_Talent_Bonus_Lance = 15.0f,
        STAT_INT_Talent_Bonus_Lance = 0.0f,
        STAT_DEX_Talent_Bonus_Lance = 0.0f,
        STAT_WILL_Talent_Bonus_Lance = 0.0f,
        STAT_LUCK_Talent_Bonus_Lance = 0.0f;
    const float STAT_LIFE_Talent_Bonus_RangeCombat = 5.0f,
        STAT_MANA_Talent_Bonus_RangeCombat = 0.0f,
        STAT_STAM_Talent_Bonus_RangeCombat = 5.0f,
        STAT_STR_Talent_Bonus_RangeCombat = 0.0f,
        STAT_INT_Talent_Bonus_RangeCombat = 0.0f,
        STAT_DEX_Talent_Bonus_RangeCombat = 10.0f,
        STAT_WILL_Talent_Bonus_RangeCombat = 0.0f,
        STAT_LUCK_Talent_Bonus_RangeCombat = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Mage = 0.0f,
        STAT_MANA_Talent_Bonus_Mage = 10.0f,
        STAT_STAM_Talent_Bonus_Mage = 0.0f,
        STAT_STR_Talent_Bonus_Mage = 0.0f,
        STAT_INT_Talent_Bonus_Mage = 10.0f,
        STAT_DEX_Talent_Bonus_Mage = 0.0f,
        STAT_WILL_Talent_Bonus_Mage = 0.0f,
        STAT_LUCK_Talent_Bonus_Mage = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Priest = 0.0f,
        STAT_MANA_Talent_Bonus_Priest = 10.0f,
        STAT_STAM_Talent_Bonus_Priest = 0.0f,
        STAT_STR_Talent_Bonus_Priest = 0.0f,
        STAT_INT_Talent_Bonus_Priest = 10.0f,
        STAT_DEX_Talent_Bonus_Priest = 0.0f,
        STAT_WILL_Talent_Bonus_Priest = 0.0f,
        STAT_LUCK_Talent_Bonus_Priest = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Monk = 10.0f,
        STAT_MANA_Talent_Bonus_Monk = 0.0f,
        STAT_STAM_Talent_Bonus_Monk = 0.0f,
        STAT_STR_Talent_Bonus_Monk = 0.0f,
        STAT_INT_Talent_Bonus_Monk = 0.0f,
        STAT_DEX_Talent_Bonus_Monk = 0.0f,
        STAT_WILL_Talent_Bonus_Monk = 10.0f,
        STAT_LUCK_Talent_Bonus_Monk = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Bard = 0.0f,
        STAT_MANA_Talent_Bonus_Bard = 0.0f,
        STAT_STAM_Talent_Bonus_Bard = 15.0f,
        STAT_STR_Talent_Bonus_Bard = 10.0f,
        STAT_INT_Talent_Bonus_Bard = 0.0f,
        STAT_DEX_Talent_Bonus_Bard = 0.0f,
        STAT_WILL_Talent_Bonus_Bard = 0.0f,
        STAT_LUCK_Talent_Bonus_Bard = 0.0f;
    const float STAT_LIFE_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_MANA_Talent_Bonus_CombatAlchemist = 10.0f,
        STAT_STAM_Talent_Bonus_CombatAlchemist = 15.0f,
        STAT_STR_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_INT_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_DEX_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_WILL_Talent_Bonus_CombatAlchemist = 0.0f,
        STAT_LUCK_Talent_Bonus_CombatAlchemist = 0.0f;
    const float STAT_LIFE_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_MANA_Talent_Bonus_TransemuteAlchemist = 10.0f,
        STAT_STAM_Talent_Bonus_TransemuteAlchemist = 15.0f,
        STAT_STR_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_INT_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_DEX_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_WILL_Talent_Bonus_TransemuteAlchemist = 0.0f,
        STAT_LUCK_Talent_Bonus_TransemuteAlchemist = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Trader = 0.0f,
        STAT_MANA_Talent_Bonus_Trader = 0.0f,
        STAT_STAM_Talent_Bonus_Trader = 10.0f,
        STAT_STR_Talent_Bonus_Trader = 0.0f,
        STAT_INT_Talent_Bonus_Trader = 0.0f,
        STAT_DEX_Talent_Bonus_Trader = 0.0f,
        STAT_WILL_Talent_Bonus_Trader = 0.0f,
        STAT_LUCK_Talent_Bonus_Trader = 10.0f;
    const float STAT_LIFE_Talent_Bonus_Blacksmith = 0.0f,
        STAT_MANA_Talent_Bonus_Blacksmith = 0.0f,
        STAT_STAM_Talent_Bonus_Blacksmith = 10.0f,
        STAT_STR_Talent_Bonus_Blacksmith = 0.0f,
        STAT_INT_Talent_Bonus_Blacksmith = 0.0f,
        STAT_DEX_Talent_Bonus_Blacksmith = 10.0f,
        STAT_WILL_Talent_Bonus_Blacksmith = 0.0f,
        STAT_LUCK_Talent_Bonus_Blacksmith = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Cook = 0.0f,
        STAT_MANA_Talent_Bonus_Cook = 0.0f,
        STAT_STAM_Talent_Bonus_Cook = 10.0f,
        STAT_STR_Talent_Bonus_Cook = 0.0f,
        STAT_INT_Talent_Bonus_Cook = 0.0f,
        STAT_DEX_Talent_Bonus_Cook = 10.0f,
        STAT_WILL_Talent_Bonus_Cook = 0.0f,
        STAT_LUCK_Talent_Bonus_Cook = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Tailor = 0.0f,
        STAT_MANA_Talent_Bonus_Tailor = 0.0f,
        STAT_STAM_Talent_Bonus_Tailor = 10.0f,
        STAT_STR_Talent_Bonus_Tailor = 0.0f,
        STAT_INT_Talent_Bonus_Tailor = 0.0f,
        STAT_DEX_Talent_Bonus_Tailor = 10.0f,
        STAT_WILL_Talent_Bonus_Tailor = 0.0f,
        STAT_LUCK_Talent_Bonus_Tailor = 0.0f;
    const float STAT_LIFE_Talent_Bonus_PotionMaker = 0.0f,
        STAT_MANA_Talent_Bonus_PotionMaker = 0.0f,
        STAT_STAM_Talent_Bonus_PotionMaker = 10.0f,
        STAT_STR_Talent_Bonus_PotionMaker = 0.0f,
        STAT_INT_Talent_Bonus_PotionMaker = 0.0f,
        STAT_DEX_Talent_Bonus_PotionMaker = 10.0f,
        STAT_WILL_Talent_Bonus_PotionMaker = 0.0f,
        STAT_LUCK_Talent_Bonus_PotionMaker = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Carpentry = 0.0f,
        STAT_MANA_Talent_Bonus_Carpentry = 0.0f,
        STAT_STAM_Talent_Bonus_Carpentry = 20.0f,
        STAT_STR_Talent_Bonus_Carpentry = 0.0f,
        STAT_INT_Talent_Bonus_Carpentry = 0.0f,
        STAT_DEX_Talent_Bonus_Carpentry = 0.0f,
        STAT_WILL_Talent_Bonus_Carpentry = 0.0f,
        STAT_LUCK_Talent_Bonus_Carpentry = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Traveler = 10.0f,
        STAT_MANA_Talent_Bonus_Traveler = 0.0f,
        STAT_STAM_Talent_Bonus_Traveler = 10.0f,
        STAT_STR_Talent_Bonus_Traveler = 0.0f,
        STAT_INT_Talent_Bonus_Traveler = 0.0f,
        STAT_DEX_Talent_Bonus_Traveler = 0.0f,
        STAT_WILL_Talent_Bonus_Traveler = 10.0f,
        STAT_LUCK_Talent_Bonus_Traveler = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Marionette = 5.0f,
        STAT_MANA_Talent_Bonus_Marionette = 0.0f,
        STAT_STAM_Talent_Bonus_Marionette = 5.0f,
        STAT_STR_Talent_Bonus_Marionette = 5.0f,
        STAT_INT_Talent_Bonus_Marionette = 0.0f,
        STAT_DEX_Talent_Bonus_Marionette = 10.0f,
        STAT_WILL_Talent_Bonus_Marionette = 0.0f,
        STAT_LUCK_Talent_Bonus_Marionette = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Shooter = 0.0f,
        STAT_MANA_Talent_Bonus_Shooter = 5.0f,
        STAT_STAM_Talent_Bonus_Shooter = 5.0f,
        STAT_STR_Talent_Bonus_Shooter = 5.0f,
        STAT_INT_Talent_Bonus_Shooter = 5.0f,
        STAT_DEX_Talent_Bonus_Shooter = 0.0f,
        STAT_WILL_Talent_Bonus_Shooter = 0.0f,
        STAT_LUCK_Talent_Bonus_Shooter = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Ninja = 0.0f,
        STAT_MANA_Talent_Bonus_Ninja = 0.0f,
        STAT_STAM_Talent_Bonus_Ninja = 0.0f,
        STAT_STR_Talent_Bonus_Ninja = 10.0f,
        STAT_INT_Talent_Bonus_Ninja = 0.0f,
        STAT_DEX_Talent_Bonus_Ninja = 0.0f,
        STAT_WILL_Talent_Bonus_Ninja = 10.0f,
        STAT_LUCK_Talent_Bonus_Ninja = 0.0f;
    const float STAT_LIFE_Talent_Bonus_ChainBlade = 0.0f,
        STAT_MANA_Talent_Bonus_ChainBlade = 0.0f,
        STAT_STAM_Talent_Bonus_ChainBlade = 0.0f,
        STAT_STR_Talent_Bonus_ChainBlade = 0.0f,
        STAT_INT_Talent_Bonus_ChainBlade = 0.0f,
        STAT_DEX_Talent_Bonus_ChainBlade = 10.0f,
        STAT_WILL_Talent_Bonus_ChainBlade = 0.0f,
        STAT_LUCK_Talent_Bonus_ChainBlade = 10.0f;
    const float STAT_LIFE_Talent_Bonus_Merlin = 0.0f,
        STAT_MANA_Talent_Bonus_Merlin = 10.0f,
        STAT_STAM_Talent_Bonus_Merlin = 5.0f,
        STAT_STR_Talent_Bonus_Merlin = 0.0f,
        STAT_INT_Talent_Bonus_Merlin = 10.0f,
        STAT_DEX_Talent_Bonus_Merlin = 0.0f,
        STAT_WILL_Talent_Bonus_Merlin = 5.0f,
        STAT_LUCK_Talent_Bonus_Merlin = 0.0f;
    const float STAT_LIFE_Talent_Bonus_Diva = 0.0f,
        STAT_MANA_Talent_Bonus_Diva = 0.0f,
        STAT_STAM_Talent_Bonus_Diva = 10.0f,
        STAT_STR_Talent_Bonus_Diva = 10.0f,
        STAT_INT_Talent_Bonus_Diva = 0.0f,
        STAT_DEX_Talent_Bonus_Diva = 10.0f,
        STAT_WILL_Talent_Bonus_Diva = 0.0f,
        STAT_LUCK_Talent_Bonus_Diva = 0.0f;
    const float STAT_LIFE_Talent_Bonus_ProfessorJ = 5.0f,
        STAT_MANA_Talent_Bonus_ProfessorJ = 5.0f,
        STAT_STAM_Talent_Bonus_ProfessorJ = 5.0f,
        STAT_STR_Talent_Bonus_ProfessorJ = 5.0f,
        STAT_INT_Talent_Bonus_ProfessorJ = 10.0f,
        STAT_DEX_Talent_Bonus_ProfessorJ = 0.0f,
        STAT_WILL_Talent_Bonus_ProfessorJ = 0.0f,
        STAT_LUCK_Talent_Bonus_ProfessorJ = 0.0f;
    const float STAT_LIFE_Talent_Bonus_MasterChef = 5.0f,
        STAT_MANA_Talent_Bonus_MasterChef = 0.0f,
        STAT_STAM_Talent_Bonus_MasterChef = 10.0f,
        STAT_STR_Talent_Bonus_MasterChef = 5.0f,
        STAT_INT_Talent_Bonus_MasterChef = 0.0f,
        STAT_DEX_Talent_Bonus_MasterChef = 10.0f,
        STAT_WILL_Talent_Bonus_MasterChef = 0.0f,
        STAT_LUCK_Talent_Bonus_MasterChef = 0.0f;
    const float STAT_LIFE_Talent_Bonus_TreasureHunter = 10.0f,
        STAT_MANA_Talent_Bonus_TreasureHunter = 0.0f,
        STAT_STAM_Talent_Bonus_TreasureHunter = 0.0f,
        STAT_STR_Talent_Bonus_TreasureHunter = 0.0f,
        STAT_INT_Talent_Bonus_TreasureHunter = 5.0f,
        STAT_DEX_Talent_Bonus_TreasureHunter = 0.0f,
        STAT_WILL_Talent_Bonus_TreasureHunter = 5.0f,
        STAT_LUCK_Talent_Bonus_TreasureHunter = 5.0f;
    const float STAT_LIFE_Talent_Bonus_PetHandler = 0.0f,
        STAT_MANA_Talent_Bonus_PetHandler = 0.0f,
        STAT_STAM_Talent_Bonus_PetHandler = 0.0f,
        STAT_STR_Talent_Bonus_PetHandler = 0.0f,
        STAT_INT_Talent_Bonus_PetHandler = 0.0f,
        STAT_DEX_Talent_Bonus_PetHandler = 0.0f,
        STAT_WILL_Talent_Bonus_PetHandler = 10.0f,
        STAT_LUCK_Talent_Bonus_PetHandler = 10.0f;
    const float STAT_LIFE_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_MANA_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_STAM_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_STR_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_INT_Talent_Bonus_MagiGraphy = 10.0f,
        STAT_DEX_Talent_Bonus_MagiGraphy = 10.0f,
        STAT_WILL_Talent_Bonus_MagiGraphy = 0.0f,
        STAT_LUCK_Talent_Bonus_MagiGraphy = 0.0f;


    for(int i = AGE::AGE_10; i < AGE::AGE_25이상 + 1 ; i++) {
        Stats initStats;
        switch(i) {
        case AGE::AGE_10:
            initStats = {STAT_LIFE_10, STAT_MANA_10, STAT_STAM_10, STAT_STR_10, STAT_INT_10, STAT_DEX_10, STAT_WILL_10, STAT_LUCK_10};
            break;
        case AGE::AGE_11:
            initStats = {STAT_LIFE_11, STAT_MANA_11, STAT_STAM_11, STAT_STR_11, STAT_INT_11, STAT_DEX_11, STAT_WILL_11, STAT_LUCK_11};
            break;
        case AGE::AGE_12:
            initStats = {STAT_LIFE_12, STAT_MANA_12, STAT_STAM_12, STAT_STR_12, STAT_INT_12, STAT_DEX_12, STAT_WILL_12, STAT_LUCK_12};
            break;
        case AGE::AGE_13:
            initStats = {STAT_LIFE_13, STAT_MANA_13, STAT_STAM_13, STAT_STR_13, STAT_INT_13, STAT_DEX_13, STAT_WILL_13, STAT_LUCK_13};
            break;
        case AGE::AGE_14:
            initStats = {STAT_LIFE_14, STAT_MANA_14, STAT_STAM_14, STAT_STR_14, STAT_INT_14, STAT_DEX_14, STAT_WILL_14, STAT_LUCK_14};
            break;
        case AGE::AGE_15:
            initStats = {STAT_LIFE_15, STAT_MANA_15, STAT_STAM_15, STAT_STR_15, STAT_INT_15, STAT_DEX_15, STAT_WILL_15, STAT_LUCK_15};
            break;
        case AGE::AGE_16:
            initStats = {STAT_LIFE_16, STAT_MANA_16, STAT_STAM_16, STAT_STR_16, STAT_INT_16, STAT_DEX_16, STAT_WILL_16, STAT_LUCK_16};
            break;
        case AGE::AGE_17:
            initStats = {STAT_LIFE_17, STAT_MANA_17, STAT_STAM_17, STAT_STR_17, STAT_INT_17, STAT_DEX_17, STAT_WILL_17, STAT_LUCK_17};
            break;
        case AGE::AGE_18:
            initStats = {STAT_LIFE_18, STAT_MANA_18, STAT_STAM_18, STAT_STR_18, STAT_INT_18, STAT_DEX_18, STAT_WILL_18, STAT_LUCK_18};
            break;
        case AGE::AGE_19:
            initStats = {STAT_LIFE_19, STAT_MANA_19, STAT_STAM_19, STAT_STR_19, STAT_INT_19, STAT_DEX_19, STAT_WILL_19, STAT_LUCK_19};
            break;
        case AGE::AGE_20:
            initStats = {STAT_LIFE_20, STAT_MANA_20, STAT_STAM_20, STAT_STR_20, STAT_INT_20, STAT_DEX_20, STAT_WILL_20, STAT_LUCK_20};
            break;
        case AGE::AGE_21:
            initStats = {STAT_LIFE_21, STAT_MANA_21, STAT_STAM_21, STAT_STR_21, STAT_INT_21, STAT_DEX_21, STAT_WILL_21, STAT_LUCK_21};
            break;
        case AGE::AGE_22:
            initStats = {STAT_LIFE_22, STAT_MANA_22, STAT_STAM_22, STAT_STR_22, STAT_INT_22, STAT_DEX_22, STAT_WILL_22, STAT_LUCK_22};
            break;
        case AGE::AGE_23:
            initStats = {STAT_LIFE_23, STAT_MANA_23, STAT_STAM_23, STAT_STR_23, STAT_INT_23, STAT_DEX_23, STAT_WILL_23, STAT_LUCK_23};
            break;
        case AGE::AGE_24:
            initStats = {STAT_LIFE_24, STAT_MANA_24, STAT_STAM_24, STAT_STR_24, STAT_INT_24, STAT_DEX_24, STAT_WILL_24, STAT_LUCK_24};
            break;
        case AGE::AGE_25이상:
            initStats = {STAT_LIFE_25_OVER, STAT_MANA_25_OVER, STAT_STAM_25_OVER, STAT_STR_25_OVER, STAT_INT_25_OVER, STAT_DEX_25_OVER, STAT_WILL_25_OVER, STAT_LUCK_25_OVER};
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
            initStats = {STAT_LIFE_Talent_Combat, STAT_MANA_Talent_Combat,
                         STAT_STAM_Talent_Combat, STAT_STR_Talent_Combat,
                         STAT_INT_Talent_Combat, STAT_DEX_Talent_Combat,
                         STAT_WILL_Talent_Combat, STAT_LUCK_Talent_Combat};
            break;
        case Talent_Lance:
            initStats = {STAT_LIFE_Talent_Lance, STAT_MANA_Talent_Lance,
                         STAT_STAM_Talent_Lance, STAT_STR_Talent_Lance,
                         STAT_INT_Talent_Lance, STAT_DEX_Talent_Lance,
                         STAT_WILL_Talent_Lance, STAT_LUCK_Talent_Lance};
            break;
        case Talent_RangeCombat:
            initStats = {STAT_LIFE_Talent_RangeCombat, STAT_MANA_Talent_RangeCombat,
                         STAT_STAM_Talent_RangeCombat, STAT_STR_Talent_RangeCombat,
                         STAT_INT_Talent_RangeCombat, STAT_DEX_Talent_RangeCombat,
                         STAT_WILL_Talent_RangeCombat, STAT_LUCK_Talent_RangeCombat};
            break;
        case Talent_Mage:
            initStats = {STAT_LIFE_Talent_Mage, STAT_MANA_Talent_Mage,
                         STAT_STAM_Talent_Mage, STAT_STR_Talent_Mage,
                         STAT_INT_Talent_Mage, STAT_DEX_Talent_Mage,
                         STAT_WILL_Talent_Mage, STAT_LUCK_Talent_Mage};
            break;
        case Talent_Priest:
            initStats = {STAT_LIFE_Talent_Priest, STAT_MANA_Talent_Priest,
                         STAT_STAM_Talent_Priest, STAT_STR_Talent_Priest,
                         STAT_INT_Talent_Priest, STAT_DEX_Talent_Priest,
                         STAT_WILL_Talent_Priest, STAT_LUCK_Talent_Priest};
            break;
        case Talent_Monk :
            initStats = {STAT_LIFE_Talent_Monk, STAT_MANA_Talent_Monk,
                         STAT_STAM_Talent_Monk, STAT_STR_Talent_Monk,
                         STAT_INT_Talent_Monk, STAT_DEX_Talent_Monk,
                         STAT_WILL_Talent_Monk, STAT_LUCK_Talent_Monk};
            break;
        case Talent_Bard :
            initStats = {STAT_LIFE_Talent_Bard, STAT_MANA_Talent_Bard,
                         STAT_STAM_Talent_Bard, STAT_STR_Talent_Bard,
                         STAT_INT_Talent_Bard, STAT_DEX_Talent_Bard,
                         STAT_WILL_Talent_Bard, STAT_LUCK_Talent_Bard};
            break;
        case Talent_CombatAlchemist :
            initStats = {STAT_LIFE_Talent_CombatAlchemist, STAT_MANA_Talent_CombatAlchemist,
                         STAT_STAM_Talent_CombatAlchemist, STAT_STR_Talent_CombatAlchemist,
                         STAT_INT_Talent_CombatAlchemist, STAT_DEX_Talent_CombatAlchemist,
                         STAT_WILL_Talent_CombatAlchemist, STAT_LUCK_Talent_CombatAlchemist};
            break;
        case Talent_TransemuteAlchemist :
            initStats = {STAT_LIFE_Talent_TransemuteAlchemist, STAT_MANA_Talent_TransemuteAlchemist,
                         STAT_STAM_Talent_TransemuteAlchemist, STAT_STR_Talent_TransemuteAlchemist,
                         STAT_INT_Talent_TransemuteAlchemist, STAT_DEX_Talent_TransemuteAlchemist,
                         STAT_WILL_Talent_TransemuteAlchemist, STAT_LUCK_Talent_TransemuteAlchemist};
            break;
        case Talent_Trader :
            initStats = {STAT_LIFE_Talent_Trader, STAT_MANA_Talent_Trader,
                         STAT_STAM_Talent_Trader, STAT_STR_Talent_Trader,
                         STAT_INT_Talent_Trader, STAT_DEX_Talent_Trader,
                         STAT_WILL_Talent_Trader, STAT_LUCK_Talent_Trader};
            break;
        case Talent_Blacksmith :
            initStats = {STAT_LIFE_Talent_Blacksmith, STAT_MANA_Talent_Blacksmith,
                         STAT_STAM_Talent_Blacksmith, STAT_STR_Talent_Blacksmith,
                         STAT_INT_Talent_Blacksmith, STAT_DEX_Talent_Blacksmith,
                         STAT_WILL_Talent_Blacksmith, STAT_LUCK_Talent_Blacksmith};
            break;
        case Talent_Cook :
            initStats = {STAT_LIFE_Talent_Cook, STAT_MANA_Talent_Cook,
                         STAT_STAM_Talent_Cook, STAT_STR_Talent_Cook,
                         STAT_INT_Talent_Cook, STAT_DEX_Talent_Cook,
                         STAT_WILL_Talent_Cook, STAT_LUCK_Talent_Cook};
            break;
        case Talent_Tailor :
            initStats = {STAT_LIFE_Talent_Tailor, STAT_MANA_Talent_Tailor,
                         STAT_STAM_Talent_Tailor, STAT_STR_Talent_Tailor,
                         STAT_INT_Talent_Tailor, STAT_DEX_Talent_Tailor,
                         STAT_WILL_Talent_Tailor, STAT_LUCK_Talent_Tailor};
            break;
        case Talent_PotionMaker :
            initStats = {STAT_LIFE_Talent_PotionMaker, STAT_MANA_Talent_PotionMaker,
                         STAT_STAM_Talent_PotionMaker, STAT_STR_Talent_PotionMaker,
                         STAT_INT_Talent_PotionMaker, STAT_DEX_Talent_PotionMaker,
                         STAT_WILL_Talent_PotionMaker, STAT_LUCK_Talent_PotionMaker};
            break;
        case Talent_Carpentry :
            initStats = {STAT_LIFE_Talent_Carpentry, STAT_MANA_Talent_Carpentry,
                         STAT_STAM_Talent_Carpentry, STAT_STR_Talent_Carpentry,
                         STAT_INT_Talent_Carpentry, STAT_DEX_Talent_Carpentry,
                         STAT_WILL_Talent_Carpentry, STAT_LUCK_Talent_Carpentry};
            break;
        case Talent_Traveler :
            initStats = {STAT_LIFE_Talent_Traveler, STAT_MANA_Talent_Traveler,
                         STAT_STAM_Talent_Traveler, STAT_STR_Talent_Traveler,
                         STAT_INT_Talent_Traveler, STAT_DEX_Talent_Traveler,
                         STAT_WILL_Talent_Traveler, STAT_LUCK_Talent_Traveler};
            break;
        case Talent_Marionette :
            initStats = {STAT_LIFE_Talent_Marionette, STAT_MANA_Talent_Marionette,
                         STAT_STAM_Talent_Marionette, STAT_STR_Talent_Marionette,
                         STAT_INT_Talent_Marionette, STAT_DEX_Talent_Marionette,
                         STAT_WILL_Talent_Marionette, STAT_LUCK_Talent_Marionette};
            break;
        case Talent_Shooter :
            initStats = {STAT_LIFE_Talent_Shooter, STAT_MANA_Talent_Shooter,
                         STAT_STAM_Talent_Shooter, STAT_STR_Talent_Shooter,
                         STAT_INT_Talent_Shooter, STAT_DEX_Talent_Shooter,
                         STAT_WILL_Talent_Shooter, STAT_LUCK_Talent_Shooter};
            break;
        case Talent_Ninja :
            initStats = {STAT_LIFE_Talent_Ninja, STAT_MANA_Talent_Ninja,
                         STAT_STAM_Talent_Ninja, STAT_STR_Talent_Ninja,
                         STAT_INT_Talent_Ninja, STAT_DEX_Talent_Ninja,
                         STAT_WILL_Talent_Ninja, STAT_LUCK_Talent_Ninja};
            break;
        case Talent_ChainBlade :
            initStats = {STAT_LIFE_Talent_ChainBlade, STAT_MANA_Talent_ChainBlade,
                         STAT_STAM_Talent_ChainBlade, STAT_STR_Talent_ChainBlade,
                         STAT_INT_Talent_ChainBlade, STAT_DEX_Talent_ChainBlade,
                         STAT_WILL_Talent_ChainBlade, STAT_LUCK_Talent_ChainBlade};
            break;
        case Talent_Merlin :
            initStats = {STAT_LIFE_Talent_Merlin, STAT_MANA_Talent_Merlin,
                         STAT_STAM_Talent_Merlin, STAT_STR_Talent_Merlin,
                         STAT_INT_Talent_Merlin, STAT_DEX_Talent_Merlin,
                         STAT_WILL_Talent_Merlin, STAT_LUCK_Talent_Merlin};
            break;
        case Talent_Diva :
            initStats = {STAT_LIFE_Talent_Diva, STAT_MANA_Talent_Diva,
                         STAT_STAM_Talent_Diva, STAT_STR_Talent_Diva,
                         STAT_INT_Talent_Diva, STAT_DEX_Talent_Diva,
                         STAT_WILL_Talent_Diva, STAT_LUCK_Talent_Diva};
            break;
        case Talent_ProfessorJ :
            initStats = {STAT_LIFE_Talent_ProfessorJ, STAT_MANA_Talent_ProfessorJ,
                         STAT_STAM_Talent_ProfessorJ, STAT_STR_Talent_ProfessorJ,
                         STAT_INT_Talent_ProfessorJ, STAT_DEX_Talent_ProfessorJ,
                         STAT_WILL_Talent_ProfessorJ, STAT_LUCK_Talent_ProfessorJ};
            break;
        case Talent_MasterChef :
            initStats = {STAT_LIFE_Talent_MasterChef, STAT_MANA_Talent_MasterChef,
                         STAT_STAM_Talent_MasterChef, STAT_STR_Talent_MasterChef,
                         STAT_INT_Talent_MasterChef, STAT_DEX_Talent_MasterChef,
                         STAT_WILL_Talent_MasterChef, STAT_LUCK_Talent_MasterChef};
            break;
        case Talent_TreasureHunter:
            initStats = {STAT_LIFE_Talent_TreasureHunter, STAT_MANA_Talent_TreasureHunter,
                         STAT_STAM_Talent_TreasureHunter, STAT_STR_Talent_TreasureHunter,
                         STAT_INT_Talent_TreasureHunter, STAT_DEX_Talent_TreasureHunter,
                         STAT_WILL_Talent_TreasureHunter, STAT_LUCK_Talent_TreasureHunter};
            break;
        case Talent_PetHandler:
            initStats = {STAT_LIFE_Talent_PetHandler, STAT_MANA_Talent_PetHandler,
                         STAT_STAM_Talent_PetHandler, STAT_STR_Talent_PetHandler,
                         STAT_INT_Talent_PetHandler, STAT_DEX_Talent_PetHandler,
                         STAT_WILL_Talent_PetHandler, STAT_LUCK_Talent_PetHandler};
            break;
        case Talent_MagiGraphy:
            initStats = {STAT_LIFE_Talent_MagiGraphy, STAT_MANA_Talent_MagiGraphy,
                         STAT_STAM_Talent_MagiGraphy, STAT_STR_Talent_MagiGraphy,
                         STAT_INT_Talent_MagiGraphy, STAT_DEX_Talent_MagiGraphy,
                         STAT_WILL_Talent_MagiGraphy, STAT_LUCK_Talent_MagiGraphy};
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
            initStats = {STAT_LIFE_Talent_Bonus_Combat, STAT_MANA_Talent_Bonus_Combat,
                         STAT_STAM_Talent_Bonus_Combat, STAT_STR_Talent_Bonus_Combat,
                         STAT_INT_Talent_Bonus_Combat, STAT_DEX_Talent_Bonus_Combat,
                         STAT_WILL_Talent_Bonus_Combat, STAT_LUCK_Talent_Bonus_Combat};
            break;
        case Talent_Bonus_Lance:
            initStats = {STAT_LIFE_Talent_Bonus_Lance, STAT_MANA_Talent_Bonus_Lance,
                         STAT_STAM_Talent_Bonus_Lance, STAT_STR_Talent_Bonus_Lance,
                         STAT_INT_Talent_Bonus_Lance, STAT_DEX_Talent_Bonus_Lance,
                         STAT_WILL_Talent_Bonus_Lance, STAT_LUCK_Talent_Bonus_Lance};
            break;
        case Talent_Bonus_RangeCombat:
            initStats = {STAT_LIFE_Talent_Bonus_RangeCombat, STAT_MANA_Talent_Bonus_RangeCombat,
                         STAT_STAM_Talent_Bonus_RangeCombat, STAT_STR_Talent_Bonus_RangeCombat,
                         STAT_INT_Talent_Bonus_RangeCombat, STAT_DEX_Talent_Bonus_RangeCombat,
                         STAT_WILL_Talent_Bonus_RangeCombat, STAT_LUCK_Talent_Bonus_RangeCombat};
            break;
        case Talent_Bonus_Mage:
            initStats = {STAT_LIFE_Talent_Bonus_Mage, STAT_MANA_Talent_Bonus_Mage,
                         STAT_STAM_Talent_Bonus_Mage, STAT_STR_Talent_Bonus_Mage,
                         STAT_INT_Talent_Bonus_Mage, STAT_DEX_Talent_Bonus_Mage,
                         STAT_WILL_Talent_Bonus_Mage, STAT_LUCK_Talent_Bonus_Mage};
            break;
        case Talent_Bonus_Priest:
            initStats = {STAT_LIFE_Talent_Bonus_Priest, STAT_MANA_Talent_Bonus_Priest,
                         STAT_STAM_Talent_Bonus_Priest, STAT_STR_Talent_Bonus_Priest,
                         STAT_INT_Talent_Bonus_Priest, STAT_DEX_Talent_Bonus_Priest,
                         STAT_WILL_Talent_Bonus_Priest, STAT_LUCK_Talent_Bonus_Priest};
            break;
        case Talent_Bonus_Monk :
            initStats = {STAT_LIFE_Talent_Bonus_Monk, STAT_MANA_Talent_Bonus_Monk,
                         STAT_STAM_Talent_Bonus_Monk, STAT_STR_Talent_Bonus_Monk,
                         STAT_INT_Talent_Bonus_Monk, STAT_DEX_Talent_Bonus_Monk,
                         STAT_WILL_Talent_Bonus_Monk, STAT_LUCK_Talent_Bonus_Monk};
            break;
        case Talent_Bonus_Bard :
            initStats = {STAT_LIFE_Talent_Bonus_Bard, STAT_MANA_Talent_Bonus_Bard,
                         STAT_STAM_Talent_Bonus_Bard, STAT_STR_Talent_Bonus_Bard,
                         STAT_INT_Talent_Bonus_Bard, STAT_DEX_Talent_Bonus_Bard,
                         STAT_WILL_Talent_Bonus_Bard, STAT_LUCK_Talent_Bonus_Bard};
            break;
        case Talent_Bonus_CombatAlchemist :
            initStats = {STAT_LIFE_Talent_Bonus_CombatAlchemist, STAT_MANA_Talent_Bonus_CombatAlchemist,
                         STAT_STAM_Talent_Bonus_CombatAlchemist, STAT_STR_Talent_Bonus_CombatAlchemist,
                         STAT_INT_Talent_Bonus_CombatAlchemist, STAT_DEX_Talent_Bonus_CombatAlchemist,
                         STAT_WILL_Talent_Bonus_CombatAlchemist, STAT_LUCK_Talent_Bonus_CombatAlchemist};
            break;
        case Talent_Bonus_TransemuteAlchemist :
            initStats = {STAT_LIFE_Talent_Bonus_TransemuteAlchemist, STAT_MANA_Talent_Bonus_TransemuteAlchemist,
                         STAT_STAM_Talent_Bonus_TransemuteAlchemist, STAT_STR_Talent_Bonus_TransemuteAlchemist,
                         STAT_INT_Talent_Bonus_TransemuteAlchemist, STAT_DEX_Talent_Bonus_TransemuteAlchemist,
                         STAT_WILL_Talent_Bonus_TransemuteAlchemist, STAT_LUCK_Talent_Bonus_TransemuteAlchemist};
            break;
        case Talent_Bonus_Trader :
            initStats = {STAT_LIFE_Talent_Bonus_Trader, STAT_MANA_Talent_Bonus_Trader,
                         STAT_STAM_Talent_Bonus_Trader, STAT_STR_Talent_Bonus_Trader,
                         STAT_INT_Talent_Bonus_Trader, STAT_DEX_Talent_Bonus_Trader,
                         STAT_WILL_Talent_Bonus_Trader, STAT_LUCK_Talent_Bonus_Trader};
            break;
        case Talent_Bonus_Blacksmith :
            initStats = {STAT_LIFE_Talent_Bonus_Blacksmith, STAT_MANA_Talent_Bonus_Blacksmith,
                         STAT_STAM_Talent_Bonus_Blacksmith, STAT_STR_Talent_Bonus_Blacksmith,
                         STAT_INT_Talent_Bonus_Blacksmith, STAT_DEX_Talent_Bonus_Blacksmith,
                         STAT_WILL_Talent_Bonus_Blacksmith, STAT_LUCK_Talent_Bonus_Blacksmith};
            break;
        case Talent_Bonus_Cook :
            initStats = {STAT_LIFE_Talent_Bonus_Cook, STAT_MANA_Talent_Bonus_Cook,
                         STAT_STAM_Talent_Bonus_Cook, STAT_STR_Talent_Bonus_Cook,
                         STAT_INT_Talent_Bonus_Cook, STAT_DEX_Talent_Bonus_Cook,
                         STAT_WILL_Talent_Bonus_Cook, STAT_LUCK_Talent_Bonus_Cook};
            break;
        case Talent_Bonus_Tailor :
            initStats = {STAT_LIFE_Talent_Bonus_Tailor, STAT_MANA_Talent_Bonus_Tailor,
                         STAT_STAM_Talent_Bonus_Tailor, STAT_STR_Talent_Bonus_Tailor,
                         STAT_INT_Talent_Bonus_Tailor, STAT_DEX_Talent_Bonus_Tailor,
                         STAT_WILL_Talent_Bonus_Tailor, STAT_LUCK_Talent_Bonus_Tailor};
            break;
        case Talent_Bonus_PotionMaker :
            initStats = {STAT_LIFE_Talent_Bonus_PotionMaker, STAT_MANA_Talent_Bonus_PotionMaker,
                         STAT_STAM_Talent_Bonus_PotionMaker, STAT_STR_Talent_Bonus_PotionMaker,
                         STAT_INT_Talent_Bonus_PotionMaker, STAT_DEX_Talent_Bonus_PotionMaker,
                         STAT_WILL_Talent_Bonus_PotionMaker, STAT_LUCK_Talent_Bonus_PotionMaker};
            break;
        case Talent_Bonus_Carpentry :
            initStats = {STAT_LIFE_Talent_Bonus_Carpentry, STAT_MANA_Talent_Bonus_Carpentry,
                         STAT_STAM_Talent_Bonus_Carpentry, STAT_STR_Talent_Bonus_Carpentry,
                         STAT_INT_Talent_Bonus_Carpentry, STAT_DEX_Talent_Bonus_Carpentry,
                         STAT_WILL_Talent_Bonus_Carpentry, STAT_LUCK_Talent_Bonus_Carpentry};
            break;
        case Talent_Bonus_Traveler :
            initStats = {STAT_LIFE_Talent_Bonus_Traveler, STAT_MANA_Talent_Bonus_Traveler,
                         STAT_STAM_Talent_Bonus_Traveler, STAT_STR_Talent_Bonus_Traveler,
                         STAT_INT_Talent_Bonus_Traveler, STAT_DEX_Talent_Bonus_Traveler,
                         STAT_WILL_Talent_Bonus_Traveler, STAT_LUCK_Talent_Bonus_Traveler};
            break;
        case Talent_Bonus_Marionette :
            initStats = {STAT_LIFE_Talent_Bonus_Marionette, STAT_MANA_Talent_Bonus_Marionette,
                         STAT_STAM_Talent_Bonus_Marionette, STAT_STR_Talent_Bonus_Marionette,
                         STAT_INT_Talent_Bonus_Marionette, STAT_DEX_Talent_Bonus_Marionette,
                         STAT_WILL_Talent_Bonus_Marionette, STAT_LUCK_Talent_Bonus_Marionette};
            break;
        case Talent_Bonus_Shooter :
            initStats = {STAT_LIFE_Talent_Bonus_Shooter, STAT_MANA_Talent_Bonus_Shooter,
                         STAT_STAM_Talent_Bonus_Shooter, STAT_STR_Talent_Bonus_Shooter,
                         STAT_INT_Talent_Bonus_Shooter, STAT_DEX_Talent_Bonus_Shooter,
                         STAT_WILL_Talent_Bonus_Shooter, STAT_LUCK_Talent_Bonus_Shooter};
            break;
        case Talent_Bonus_Ninja :
            initStats = {STAT_LIFE_Talent_Bonus_Ninja, STAT_MANA_Talent_Bonus_Ninja,
                         STAT_STAM_Talent_Bonus_Ninja, STAT_STR_Talent_Bonus_Ninja,
                         STAT_INT_Talent_Bonus_Ninja, STAT_DEX_Talent_Bonus_Ninja,
                         STAT_WILL_Talent_Bonus_Ninja, STAT_LUCK_Talent_Bonus_Ninja};
            break;
        case Talent_Bonus_ChainBlade :
            initStats = {STAT_LIFE_Talent_Bonus_ChainBlade, STAT_MANA_Talent_Bonus_ChainBlade,
                         STAT_STAM_Talent_Bonus_ChainBlade, STAT_STR_Talent_Bonus_ChainBlade,
                         STAT_INT_Talent_Bonus_ChainBlade, STAT_DEX_Talent_Bonus_ChainBlade,
                         STAT_WILL_Talent_Bonus_ChainBlade, STAT_LUCK_Talent_Bonus_ChainBlade};
            break;
        case Talent_Bonus_Merlin :
            initStats = {STAT_LIFE_Talent_Bonus_Merlin, STAT_MANA_Talent_Bonus_Merlin,
                         STAT_STAM_Talent_Bonus_Merlin, STAT_STR_Talent_Bonus_Merlin,
                         STAT_INT_Talent_Bonus_Merlin, STAT_DEX_Talent_Bonus_Merlin,
                         STAT_WILL_Talent_Bonus_Merlin, STAT_LUCK_Talent_Bonus_Merlin};
            break;
        case Talent_Bonus_Diva :
            initStats = {STAT_LIFE_Talent_Bonus_Diva, STAT_MANA_Talent_Bonus_Diva,
                         STAT_STAM_Talent_Bonus_Diva, STAT_STR_Talent_Bonus_Diva,
                         STAT_INT_Talent_Bonus_Diva, STAT_DEX_Talent_Bonus_Diva,
                         STAT_WILL_Talent_Bonus_Diva, STAT_LUCK_Talent_Bonus_Diva};
            break;
        case Talent_Bonus_ProfessorJ :
            initStats = {STAT_LIFE_Talent_Bonus_ProfessorJ, STAT_MANA_Talent_Bonus_ProfessorJ,
                         STAT_STAM_Talent_Bonus_ProfessorJ, STAT_STR_Talent_Bonus_ProfessorJ,
                         STAT_INT_Talent_Bonus_ProfessorJ, STAT_DEX_Talent_Bonus_ProfessorJ,
                         STAT_WILL_Talent_Bonus_ProfessorJ, STAT_LUCK_Talent_Bonus_ProfessorJ};
            break;
        case Talent_Bonus_MasterChef :
            initStats = {STAT_LIFE_Talent_Bonus_MasterChef, STAT_MANA_Talent_Bonus_MasterChef,
                         STAT_STAM_Talent_Bonus_MasterChef, STAT_STR_Talent_Bonus_MasterChef,
                         STAT_INT_Talent_Bonus_MasterChef, STAT_DEX_Talent_Bonus_MasterChef,
                         STAT_WILL_Talent_Bonus_MasterChef, STAT_LUCK_Talent_Bonus_MasterChef};
            break;
        case Talent_Bonus_TreasureHunter:
            initStats = {STAT_LIFE_Talent_Bonus_TreasureHunter, STAT_MANA_Talent_Bonus_TreasureHunter,
                         STAT_STAM_Talent_Bonus_TreasureHunter, STAT_STR_Talent_Bonus_TreasureHunter,
                         STAT_INT_Talent_Bonus_TreasureHunter, STAT_DEX_Talent_Bonus_TreasureHunter,
                         STAT_WILL_Talent_Bonus_TreasureHunter, STAT_LUCK_Talent_Bonus_TreasureHunter};
            break;
        case Talent_Bonus_PetHandler:
            initStats = {STAT_LIFE_Talent_Bonus_PetHandler, STAT_MANA_Talent_Bonus_PetHandler,
                         STAT_STAM_Talent_Bonus_PetHandler, STAT_STR_Talent_Bonus_PetHandler,
                         STAT_INT_Talent_Bonus_PetHandler, STAT_DEX_Talent_Bonus_PetHandler,
                         STAT_WILL_Talent_Bonus_PetHandler, STAT_LUCK_Talent_Bonus_PetHandler};
            break;
        case Talent_Bonus_MagiGraphy:
            initStats = {STAT_LIFE_Talent_Bonus_MagiGraphy, STAT_MANA_Talent_Bonus_MagiGraphy,
                         STAT_STAM_Talent_Bonus_MagiGraphy, STAT_STR_Talent_Bonus_MagiGraphy,
                         STAT_INT_Talent_Bonus_MagiGraphy, STAT_DEX_Talent_Bonus_MagiGraphy,
                         STAT_WILL_Talent_Bonus_MagiGraphy, STAT_LUCK_Talent_Bonus_MagiGraphy};
            break;
        default:
            break;
        }
        vecStatTalentBonus.push_back(initStats);
    }
}
