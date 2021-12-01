/*
 *
 * #include "statistiques.h"
#include <QDialog>
#include <QSqlQuery>

::stat_etat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_etat)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistique");

    //***************************************************************
    QSqlQuery q1,q2,q3;
    qreal Oui=0, Non=0;

    q1.prepare("SELECT * FROM Visites WHERE abonnement='Oui'");
    q1.exec();
    q2.prepare("SELECT * FROM Visites WHERE abonnement='Non'");
    q2.exec();

    while (q1.next()){Oui++;}
    while (q2.next()){Non++;}


        // Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("Abonnés / Non Abonnés ");

        // Assign values for each bar
        *set0 << Oui <<Non;


        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        //QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
        series->append(set0);

        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);

        // Set title
        chart->setTitle("Abonnements");

        // Define starting animation
        // NoAnimation, GridAxisAnimations, SeriesAnimations
        chart->setAnimationOptions(QChart::AllAnimations);

        // Holds the category titles
        QStringList categories;
        categories << "Les Visites" ;

        // Adds categories to the axes
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();

        // 1. Bar chart
        chart->setAxisX(axis,series);

        // 2. Stacked Bar chart
        // chart->setAxisY(axis, series);

        // Define where the legend is displayed
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Used to change the palette
        QPalette pal = qApp->palette();

        // Change the color around the chart widget and text
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));

        // Apply palette changes to the application
        qApp->setPalette(pal);
        chartView->setParent(ui->horizontalFrame);
}
*/
