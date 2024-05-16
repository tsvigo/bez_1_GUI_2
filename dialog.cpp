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
#include <unistd.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////
int variable_synapse_index_counter=10100; 
long long variable_error;
int var =100;
 int neuron_index = 0, synapse_index = 0;
QString Nazvaniye_fayla_s_neyronami_i_signalom;
std::vector<unsigned long long> list_of_neurons={};
std::vector<unsigned long long> list_of_synapses={};
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
//     Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
//       tr("Открыть файл neyroni_i_signal.txt без 1 который надо подстроить."), 
//       "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/", tr("Text Files (*.txt)"));
//########################################################################################################
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор
Nazvaniye_fayla_s_neyronami_i_signalom="/home/viktor/my_scripts_4/kraynie_znacheniya/neyrony_0.txt";


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

    QFile file(  
 //   "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
    "/home/viktor/my_scripts_4/kraynie_znacheniya/sinapsy_2147483647.txt"
    );
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
 // QApplication app(argc, argv);
 // std::cout
 qDebug()  << "нейронов: " << list_of_neurons.size();
     //  std::cout 
   qDebug()     << "нейрон 0: " << list_of_neurons[0];
 //  std::cout
  qDebug()  << "синапсов: " << list_of_synapses.size();
  //    qDebug() << "синапс 0: " << list_of_synapses[0]; // сегментация фаулт
  
//  auto it = list_of_synapses.end(); // point at the last element
// it = std::prev(it); // move one step back to get the first element (wraps around) 

   //   a.exit(0);
   // sleep(60);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: решение
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
b:
// int neuron_index = 0, synapse_index = 0;
    for ( var = 100; 
   var < 200
   //,
  // synapse_index<10101
    
  // var <(int) list_of_neurons.size()//+1
     ; ++var) // This is the range of neurons
  //   if (synapse_index<10101 && neuron_index < 200 )
    {
        for ( neuron_index = 0, synapse_index = 0;
       // neuron_index <(int) list_of_neurons.size()+1
     //   neuron_index < 200
      //   &&
     // ,
          /*,*/ synapse_index < 10100; 
            ++neuron_index, synapse_index = synapse_index + 100)
        
        { // // ошибка сегментации
        

        if (neuron_index < 200)
            list_of_neurons[var]=list_of_neurons[var] +  (list_of_neurons[neuron_index]/  
             list_of_synapses[synapse_index]); // + на - 
              


        } // вычитаем нейроны
    }
    
    for (int   neuron_index = 100, synapse_index = 10000;
    // neuron_index < (int)list_of_neurons.size()+1; 
 //neuron_index < 200
    // &&
   // ,
 synapse_index < 10100
 ; //200
      ++neuron_index, ++synapse_index)
    {
   // if ( neuron_index < 200)
   if (list_of_synapses[synapse_index]!=0)
        list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -
    }
//   variable_error     = 1073741824-  list_of_neurons[200] ; // WARNING: изменение
//########################################################################################################   
//variable_error     = list_of_neurons[200]-1073741824 ;
    variable_error     =   1073741824-list_of_neurons[200] ;
    // надо чтобы list_of_neurons[200] стал равен 1073741824 или больше
//########################################################################################################    
 std::cout << "variable_error = " << variable_error<< std::endl;
     if  ( variable_error <0)
    {
        
        std::cout << "Программа считает что это 1." << std::endl;
        std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
       // SUMMARY: AddressoverflowSanitizer: heap-buffer- ../../my_projects_qt_2/bez_1_GUI_2/dialog.cpp:147 
       if (variable_synapse_index_counter>0) // вот была ошибка
       {
       // если все синапсы пройдены, поставлены на минимумы и ошибка не пропала.
             if (list_of_synapses[variable_synapse_index_counter] < 2147483646 
             && list_of_synapses[variable_synapse_index_counter] >0
             ) // < 2147483646 или > 1
     {
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]-1;  // +1 или -1
        variable_synapse_index_counter--;
        std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
       goto b;   
     }
     }
   else
      {
       std::cout << "все синапсы пройдены, поставлены на минимумы и ошибка не пропала." << std::endl;
       std::cout << "list_of_neurons[200] = " <<list_of_neurons[200]<< std::endl;
   }
//########################################################################################################   
    } // if  ( variable_error <0) // ошибка не пропала
    else {        std::cout << "Программа считает что это не 1." << std::endl;   goto d;  }
//########################################################################################################




 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 d:
//auto it = list_of_synapses.rbegin(); // point at the last element
//if (it != list_of_synapses.rend()) { // check if we're not at the end
//    it--; // move one step back to get the first element
//}

auto it = list_of_synapses.begin();
size_t idx = std::distance(list_of_synapses.begin(), it);
 std::cout << "Текущий индекс синапсов: " << idx<<std::endl; 
 auto it2 = list_of_neurons.begin();
size_t idx2 = std::distance(list_of_neurons.begin(), it2);
 std::cout << "Текущий индекс нейронов: " << idx2<<std::endl;
//########################################################################################################
// записываем вектор синапсов в файл
    // Convert the vector of unsigned long longs to a QString
//    QString synapseText;
//    for (const auto& synapse : list_of_synapses) {
//        synapseText += QString::number(synapse) + "\n"; // add a newline character at the end of each line
//    }

//    // Set the text in the QTextEdit widget
//    ui->textEdit->setText(synapseText);
    
//    // Create a QTextEdit object and set its text (e.g., from user input)
//   // QTextEdit* textEdit = new QTextEdit();
//   // QString text = "Initial text"; // or get the text from the widget

//    // Save the text to a file
//    QFile file2("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"); // adjust the filename as needed
//    if (!file2.open(QFile::WriteOnly | QFile::Truncate)) {
//        qWarning() << "Failed to open file";
       
//    }

//    QTextStream stream(&file);
//    stream <<ui->textEdit->toPlainText(); // write the text to the file

//    file2.close();
//########################################################################################################  
//    QFile file2( "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
//    if (!file2.open(QFile::WriteOnly | QFile::Truncate)) {
//        throw std::runtime_error("Failed to open file");
//    }

//    QTextStream out(&file2);
//    for (unsigned long long synapse : list_of_synapses) {
//       out << synapse << "\n";
//   }

//   file2.close();
 //########################################################################################################
//    std::cout << "The error has disappeared. Variable error = " << variable_error<< ". Это выход. "<<std::endl;
           std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
// std::cout << "variable_error = " << variable_error<< std::endl;







//########################################################################################################    
}

Dialog::~Dialog()
{
    delete ui;
}

