#pragma once
#ifndef __DIE_H__
#define __DIE_H__

class Die
{
    public:
        Die() {};
        Die( int sides );
        int roll() const;
    private:
        int sides;
};

#endif
