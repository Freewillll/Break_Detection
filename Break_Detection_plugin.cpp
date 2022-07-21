/* Break_Detection_plugin.cpp
 * This is a test plugin, you can use it as a demo.
 * 2022-7-20 : by Freewill
 */
 
#include "v3d_message.h"
#include <vector>
#include "Break_Detection_plugin.h"
#include "log.h"
#include "help_func.h"
#include "basic_surf_objs.h"
using namespace std;
 
QStringList Break_Detection::menulist() const
{
	return QStringList() 
		<<tr("menu1")
		<<tr("menu2")
		<<tr("about");
}

QStringList Break_Detection::funclist() const
{
	return QStringList()
		<<tr("func1")
		<<tr("func2")
		<<tr("help");
}

void Break_Detection::domenu(const QString &menu_name, V3DPluginCallback2 &callback, QWidget *parent)
{
	if (menu_name == tr("menu1"))
	{
		v3d_msg("To be implemented.");
	}
	else if (menu_name == tr("menu2"))
	{
		v3d_msg("To be implemented.");
	}
	else
	{
		v3d_msg(tr("This is a test plugin, you can use it as a demo.. "
			"Developed by Freewill, 2022-7-20"));
	}
}

bool Break_Detection::dofunc(const QString & func_name, const V3DPluginArgList & input, V3DPluginArgList & output, V3DPluginCallback2 & callback,  QWidget * parent)
{
	vector<char*> infiles, inparas, outfiles;
	if(input.size() >= 1) infiles = *((vector<char*> *)input.at(0).p);
	if(input.size() >= 2) inparas = *((vector<char*> *)input.at(1).p);
	if(output.size() >= 1) outfiles = *((vector<char*> *)output.at(0).p);
    qInstallMessageHandler(messageOutput);
    QString curPath = QDir::currentPath();
    QString qDebugfilePath = curPath.append("/qDebug.txt");
    std::cout<<"debug file path:"<<qDebugfilePath.toStdString().c_str()<<std::endl;

    if (func_name == tr("break_detection"))
	{
        qDebug()<<"--------------------------start func-----------------------------------------------------";
        QString swcfile = infiles[0];
        QString outfile = outfiles[0];
        NeuronTree nt = readSWC_file(swcfile);
        QList<NeuronSWC> newtree;
        double disthre=0;
        int k=0;
        disthre = (inparas.size()>=k+1) ? atof(inparas[0]) : 0;
        connect_swc(nt, disthre);
        writeSWC_file(outfile, nt);
        qDebug()<<"--------------------------end func--------------------------------------------------------";

	}
	else if (func_name == tr("func2"))
	{
		v3d_msg("To be implemented.");
	}
	else if (func_name == tr("help"))
	{
		v3d_msg("To be implemented.");
	}
	else return false;

	return true;
}

