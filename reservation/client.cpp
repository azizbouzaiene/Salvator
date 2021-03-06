#include "client.h"

Client::Client(QString CIN,QString Nom, QString Prenom,QString Mail,  QString Tel, QDate Dat)
{
    this->CIN = CIN;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Mail = Mail;
   this->Tel = Tel;
   this->Dat=Dat;
}
bool Client::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into reservation (CIN, Nom, Prenom, Mail,  Tel,Dat)" "values (:CIN, :Nom, :Prenom, :Mail, :Tel, :Dat)");

    query.bindValue(":CIN",CIN);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Mail",Mail);
    query.bindValue(":Tel",Tel);
    query.bindValue(":Dat",Dat);

    return query.exec();

}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from reservation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Dat"));


    return model;


}

bool Client::modifier(QString CIN, QString Nom, QString Prenom, QString Mail, QString Tel, QDate Dat)
{
    QSqlQuery query;
    query.prepare("UPDATE reservation SET CIN= :CIN,Nom= :Nom,Prenom= :Prenom,Mail= :Mail,Tel= :Tel,Dat= :Dat Where CIN= :CIN");
    query.bindValue(":CIN",CIN);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Mail",Mail);
    query.bindValue(":Tel",Tel);
    query.bindValue(":Dat",Dat);
    return query.exec();
}

bool Client::supprimer(QString CIN)
{
    QSqlQuery query;
    query.prepare("Delete from reservation where CIN= :CIN");
    query.bindValue(":CIN",CIN);
    return query.exec();
}
QSqlQueryModel * Client::cherchercin(QString CIN)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from reservation where CIN= :CIN");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Dat"));


    return model;


}
