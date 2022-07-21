#ifndef HELP_FUNC_H
#define HELP_FUNC_H
#include "basic_surf_objs.h"
#include <vector>

bool fexists(QString filename);
bool SortSWC(QList<NeuronSWC> & neurons, QList<NeuronSWC> & result, V3DLONG newrootid, double thres);
bool export_list2file(QList<NeuronSWC> & lN, QString fileSaveName, QString fileOpenName);
QVector< QVector<V3DLONG> > get_neighbors(QList<NeuronSWC> &neurons, const QHash<V3DLONG,V3DLONG> & LUT);
QHash<V3DLONG, V3DLONG> getUniqueLUT(QList<NeuronSWC> &neurons, QHash<V3DLONG, NeuronSWC> & LUT_newid_to_node);
double computeDist2(const NeuronSWC & s1, const NeuronSWC & s2);
bool combine_linker(std::vector<QList<NeuronSWC> > & linker, QList<NeuronSWC> & combined);
QList<V3DLONG> DFS(QVector< QVector<V3DLONG> > neighbors, V3DLONG newrootid, V3DLONG siz);
void connect_swc(NeuronTree nt, QList<NeuronSWC>& newNeuron, double disThr, QStringList& swcinfo);
bool connect_swc(NeuronTree& nt, double disthre, QStringList& swcinfo);
NeuronTree pruneswc(NeuronTree nt, double length);

#endif // HELP_FUNC_H
