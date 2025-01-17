#ifndef ONLYET_fzRecorder_H
#define ONLYET_fzRecorder_H

#include <QtWidgets/QMainWindow>
#include "ui_fzRecorder.h"

#include <memory>

namespace onlyet {
class IRecorder;
}

class QTimer;

class fzRecorder : public QMainWindow
{
    Q_OBJECT

public:
    fzRecorder(QWidget *parent = Q_NULLPTR);
    ~fzRecorder();

private slots:
    void startBtnClicked();
    void pauseBtnClicked();
    void stopBtnClicked();
    void updateRecordTime();

    private:
    void initUI();

private:
    Ui::fzRecorderClass              ui;
    std::unique_ptr<onlyet::IRecorder> m_recorder;
    QTimer*                            m_recordTimer    = nullptr;
    int                                m_recordDuration = 0;
    bool                               m_started        = false;
    bool                               m_paused         = false;
};

#endif  // !ONLYET_fzRecorder_H
