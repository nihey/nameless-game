/* 
 * File:   Consumable.h
 * Author: Nihey
 *
 * Created on 8 de Junho de 2012, 14:10
 */

#ifndef CONSUMABLE_H
#define	CONSUMABLE_H

class Character;

class Consumable {
    
    
    public:

        Consumable();

        virtual int Restore() = 0;
        virtual int Revive() = 0;
        virtual bool ConsumableBy(Character* pChar) = 0;
        virtual void Consume(Character* pChar) = 0;
        
        virtual ~Consumable();

};

#endif	/* CONSUMABLE_H */

