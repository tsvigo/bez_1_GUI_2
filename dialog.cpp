#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include <fstream>
#include <iostream>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////
int variable_synapse_index_counter=10100; 
long long variable_error;
int var ;
QString Nazvaniye_fayla_s_neyronami_i_signalom;
std::vector<unsigned long long> list_of_neurons;
std::vector<unsigned long long> list_of_synapses;
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
    std::cout << "bez_1_GUI_2" << std::endl;  
//########################################################################################################
/// Сначала укажем какой файл с нейронами подстроить.
     Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
       tr("Открыть файл neyroni_i_signal.txt без 1 который надо подстроить."), 
       "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/", tr("Text Files (*.txt)"));
//########################################################################################################
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор



const QString& fileName=Nazvaniye_fayla_s_neyronami_i_signalom;
{
    std::ifstream file(fileName.toStdString().c_str());
    if (file.is_open()) {
        unsigned long long value;
        while (file >> value) {
            list_of_neurons.push_back(value);
        }
        file.close();
    } else {
        qDebug() << "Unable to open file: " << fileName;
    }
}
//########################################################################################################   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// загрузка синапсов из файла в вектор

    QFile file(  "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        unsigned long long synaps = line.toULongLong(&ok);
        if (!ok) {
            throw std::runtime_error("Invalid synaps value in file");
        }
        list_of_synapses.push_back(synaps);
    }

    file.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: решение
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
b:
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200 && /*,*/ synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            list_of_neurons[var]=list_of_neurons[var]-  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]); // + на -   
        } // вычитаем нейроны
    }
    
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
        list_of_neurons[200] = list_of_neurons[200] - (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -
    }
//   variable_error     = 1073741824-  list_of_neurons[200] ; // WARNING: изменение
//########################################################################################################   
//variable_error     = list_of_neurons[200]-1073741824 ;
    variable_error     =   1073741824-list_of_neurons[200] ;
//########################################################################################################    
 std::cout << "variable_error = " << variable_error<< std::endl;
     if  ( variable_error <0)
    {
        
        std::cout << "Программа считает что это 1." << std::endl;
        
             if (list_of_synapses[variable_synapse_index_counter] < 2147483646 ) // < 2147483646 или > 1
     {
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]+1;  // +1 или -1
       goto b;   
     }
   
    }
    else {        std::cout << "Программа считает что это не 1." << std::endl;   goto d;  }
//########################################################################################################




 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 d:
  //########################################################################################################
// записываем вектор синапсов в файл
//########################################################################################################  
     QFile file2( "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
    if (!file2.open(QFile::WriteOnly | QFile::Text)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream out(&file2);
    for (unsigned long long synapse : list_of_synapses) {
        out << synapse << "\n";
    }

    file2.close();
 //########################################################################################################
    std::cout << "The error has disappeared. Variable error = " << variable_error<< ". Это выход. "<<std::endl;
            std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
 std::cout << "variable_error = " << variable_error<< std::endl;







//########################################################################################################    
}

Dialog::~Dialog()
{
    delete ui;
}

