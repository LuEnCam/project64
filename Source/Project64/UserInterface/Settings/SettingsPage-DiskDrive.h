#pragma once

class CDiskDrivePage :
    public CSettingsPageImpl<CDiskDrivePage>,
    public CSettingsPage
{

    BEGIN_MSG_MAP_EX(CDiskDrivePage)
    {
        COMMAND_ID_HANDLER_EX(IDC_SELECT_IPL_JP_DIR, SelectIplDirJp);
        COMMAND_ID_HANDLER_EX(IDC_SELECT_IPL_US_DIR, SelectIplDirUs);
        COMMAND_ID_HANDLER_EX(IDC_SELECT_IPL_TL_DIR, SelectIplDirTl);
        COMMAND_ID_HANDLER_EX(IDC_SELECT_MODEM_ROM_DIR, SelectModemRomDir);
        COMMAND_HANDLER_EX(IDC_IPL_JP_DIR, EN_UPDATE, IplDirJpChanged);
        COMMAND_HANDLER_EX(IDC_IPL_US_DIR, EN_UPDATE, IplDirUsChanged);
        COMMAND_HANDLER_EX(IDC_IPL_TL_DIR, EN_UPDATE, IplDirTlChanged);
        COMMAND_HANDLER_EX(IDC_MODEM_ROM_DIR, EN_UPDATE, ModemRomChanged);
        COMMAND_HANDLER_EX(IDC_DISKSAVETYPE, LBN_SELCHANGE, ComboBoxChanged);
    }
    END_MSG_MAP()

    enum
    {
        IDD = IDD_Settings_DiskDrive
    };

public:
    CDiskDrivePage(HWND hParent, const RECT & rcDispay);

    LanguageStringID PageTitle(void)
    {
        return TAB_DISKDRIVE;
    }
    void HidePage(void);
    void ShowPage(void);
    void ApplySettings(bool UpdateScreen);
    bool EnableReset(void);
    void ResetPage(void);

private:
    void SelectIplDirJp(UINT Code, int id, HWND ctl);
    void SelectIplDirUs(UINT Code, int id, HWND ctl);
    void SelectIplDirTl(UINT Code, int id, HWND ctl);
    void SelectModemRomDir(UINT Code, int id, HWND ctl);

    void IplDirJpChanged(UINT Code, int id, HWND ctl);
    void IplDirUsChanged(UINT Code, int id, HWND ctl);
    void IplDirTlChanged(UINT Code, int id, HWND ctl);
    void ModemRomChanged(UINT Code, int id, HWND ctl);

    void UpdatePageSettings(void);
    void SelectFile(LanguageStringID Title, CModifiedEditBox & EditBox);
    CModifiedEditBox m_IplDirJp;
    CModifiedEditBox m_IplDirUs;
    CModifiedEditBox m_IplDirTl;
    CModifiedEditBox m_ModemRomDirJp;

    bool m_InUpdateSettings;
};
