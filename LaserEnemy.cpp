#include "LaserEnemy.h"
#include "Barrier.h"
#include "Game.h"
#include "qgraphicsscene.h"
#include "endscreen.h"

#include <QTimer>
#include <QList>

extern Game * game;
int barrierhealth = 0;
int shiphealth=0;

LaserEnemy::LaserEnemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Assign pixmap to item
    QPixmap bullet_pixmap(":/images/bullet2.png");
    bullet_pixmap = bullet_pixmap.scaled(laser_width, laser_height);
    setPixmap(QPixmap(bullet_pixmap));
    setPos(x() + 100, 100);

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(5);
}

void LaserEnemy::move()
{
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            switch(game->health->getHealth()){
                case 3:
                    //decrease health
                    game->health->decrease();
                    scene()->removeItem(this);
                    delete this;
                    // put new picture
                    return;
                case 2:
                    //decrease health
                    game->health->decrease();
                    scene()->removeItem(this);
                    delete this;
                    //put new picture
                    return;
                case 1:
                    //decrease health
                    game->health->decrease();
                    //WE GOTTA MAKE AN END SCREEN

                    //removing from scene, but they still exist in memory
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    //deleting to remove memory usage
                    delete colliding_items[i];
                    delete this;
                    scorecheck(); // doing highscore stuff


                    return;
                default:
                    return;
            }

        }
        if (typeid(*(colliding_items[i])) == typeid(Barrier))
        {
            //removing from scene, but they still exist in memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //deleting to remove memory usage
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //moving Laser Down
    setPos(x(), y() + 1);
    if (pos().y() > gameScreenHeight)
    {
        scene()->removeItem(this);
        delete this;
    }
}
void LaserEnemy::scorecheck(){
   int score1 = game->health->getHealth();
    // Open highscore file
//        scores_file.close();
//        scores_file.setFileName("SpaceScore.txt");

//        qDebug()<<"after name";
//        if(!scores_file.open(QIODevice::ReadWrite)){
//            qDebug()<<"in open";
//            qCritical() << "Could not open file!";
//            qCritical() << scores_file.errorString();
//            return;
//        }
//        qDebug()<<"after open";
//        scores_stream.setDevice(&scores_file);


//     // Read file and put data in 2 vectors
//        score_ctr = 0;
//        while (!scores_stream.atEnd()) {
//            QString line = scores_stream.readLine();
//            QStringList fields = line.split(" | ");
//            if(fields[0] == ""){
//                break;
//            }
//            names.push_back(fields[0]);
//            scores.push_back(fields[1].toInt());
//            score_ctr++;
//        }


//    // Writes score into file if new highscore
//            bool new_highscore = false;
//                if(score_ctr < 3){
//                    // If less than 3 scores in file...
//                    score_pos = score_ctr;
//                    names.push_back("-");
//                    scores.push_back(score1);
//                    for(int j = score_ctr+1; j < 3; j++){
//                        names.push_back("-");
//                        scores.push_back(0);
//                    }
//                    new_highscore = true;
//                }else{
//                    // Compare to highscores to current score
//                    for(uint i = 0; i < scores.size(); i++){
//                        if(score1 > scores[i] && !new_highscore){
//                            score_pos = i;
//                            new_highscore = true;
//                        }
//                    }
//                }


//    if(new_highscore == false){
//                scores_file.resize(0); // Erase file content
//                for(uint j = 0; j < scores.size(); j++){
//                    scores_stream << names[j] << " | " << QString::number(scores[j]) << "\n";
//                }
//                //display_highscores();
//                scores_file.flush();
//                scores_file.close();
//            }else{
//                //new_highscore_input();
//            }


//    if(scores_file.isOpen()){
//            // Write vectors back into file
//            scores_file.resize(0); // Erase file content
//            for(uint j = 0; j < scores.size(); j++){
//                scores_stream << names[j] << " | " << QString::number(scores[j]) << "\n";
//            }
//            scores_file.flush();
//            scores_file.close();
//        }
    EndScreen *endscreen = new EndScreen();
    endscreen->show();
    game->hide();

}


