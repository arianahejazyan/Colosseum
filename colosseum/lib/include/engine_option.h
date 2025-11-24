#ifndef ENGINE_OPTION_H
#define ENGINE_OPTION_H

#include <QString>
#include <QVariant>

namespace colosseum
{

class EngineOption
{
    public:


    private:
    
        QString m_name;
        QVariant m_value;
        QVariant m_default_value;
        QMetaType m_type; 
};

class EngineButtonOption : EngineOption
{

};

class EngineTextOption : EngineOption
{

};

class EngineSpinOption : EngineOption
{

};

class EngineComboOption : EngineOption
{

};

class EngineCheckOption : EngineOption
{

};

} // namspace colosseum

#endif /* ENGINE_OPTION_H */