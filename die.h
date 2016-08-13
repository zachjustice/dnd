#pragma once
#ifndef __DIE_H__
#define __DIE_H__

class Die
{
    public:
        Die() {};
        Die( const int sides );
        int roll() const;
        static void initDie();
        static void initDie( int s );
    private:
        int sides;
};

#endif
