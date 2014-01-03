/**
  * Copyright [2013-2014] [OHsystem]
  * 
  * OHSystem is free software: You can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  * 
  * Please save the copyrights and notifications on the footer.
  * 
  * You can contact the developers on: ohsystem-public@googlegroups.com
  * or join us directly here: https://groups.google.com/d/forum/ohsystem-public
  * 
  * Visit us also on http://ohsystem.net/ and keep track always of the latest
  * features and changes.
  * 
  * 
  * This is modified from GHOST++: http://ghostplusplus.googlecode.com/
  * Official GhostPP-Forum: http://ghostpp.com/
 */

#ifndef STATSW3MMD_H
#define STATSW3MMD_H

//
// CStatsW3MMD
//

typedef pair<uint32_t,string> VarP;

class CStatsW3MMD : public CStats
{
private:
	string m_Category;
	uint32_t m_NextValueID;
	uint32_t m_NextCheckID;
	map<uint32_t,string> m_PIDToName;			// pid -> player name (e.g. 0 -> "Varlock") --- note: will not be automatically converted to lower case
	map<uint32_t,string> m_Flags;				// pid -> flag (e.g. 0 -> "winner")
	map<uint32_t,bool> m_FlagsLeaver;			// pid -> leaver flag (e.g. 0 -> true) --- note: will only be present if true
	map<uint32_t,bool> m_FlagsPracticing;		// pid -> practice flag (e.g. 0 -> true) --- note: will only be present if true
	map<string,string> m_DefVarPs;				// varname -> value type (e.g. "kills" -> "int")
	map<VarP,int32_t> m_VarPInts;				// pid,varname -> value (e.g. 0,"kills" -> 5)
	map<VarP,double> m_VarPReals;				// pid,varname -> value (e.g. 0,"x" -> 0.8)
	map<VarP,string> m_VarPStrings;				// pid,varname -> value (e.g. 0,"hero" -> "heroname")
	map<string, vector<string> > m_DefEvents;	// event -> vector of arguments + format

public:
	CStatsW3MMD( CBaseGame *nGame, string nCategory );
	virtual ~CStatsW3MMD( );

	virtual bool ProcessAction( CIncomingAction *Action );
	virtual void Save( CGHost *GHost, CGHostDB *DB, uint32_t GameID );
	virtual vector<string> TokenizeKey( string key );
};

#endif
