#include "regina.h"

Regina::Regina(bool c, int p, Scacchiera* parent) :Pezzi(c,p,parent),mosseacroce(c,p,parent), Mosseax(c,p,parent)
{

}

std::vector<int> Regina::move() const
{
    std::vector<int> mossepossibili=mosseacroce::move();
    std::vector<int> mossealfiere=Mosseax::move();
    mossepossibili.insert(mossepossibili.begin(),mossealfiere.begin(),mossealfiere.end());
    return mossepossibili;
}
