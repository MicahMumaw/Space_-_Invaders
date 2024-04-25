#include <Barrier.h>
#include "qgraphicsscene.h"
#include "Game.h"

Barrier::Barrier()
{
    setBrush(QColorConstants::Svg::violet);
    setRect(0, 0, barrier_width, barrier_height);
}
