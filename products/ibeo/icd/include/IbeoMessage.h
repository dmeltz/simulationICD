#ifndef IBEO_MESSAGE_H
#define IBEO_MESSAGE_H

/*
* IbeoMessage.h
* Ibeo message to send
* Author: Binyamin Appelbaum
* Date: 23.04.18
*/

#include "IMessage.h"
#include "IbeoData.h"
#include "IbeoStructs.h"

class ICommunication; // forward declaration

class IbeoMessage : public IMessage<IbeoData>{
private:
	int m_pointCounter = 0;

	void FillPoints(SibeoScanData& msg, unsigned char layerEcho, const std::vector<double>& ranges);

public:
	IbeoMessage(float hertz);

	virtual ~IbeoMessage() = default;

	virtual void FillMessage(const IbeoData& data) override;

	virtual int SendMessage(ICommunication* comm) const override;

	virtual int GetMessageSize() const override;

    void InitMessage();
};

#endif // IBEO_MESSAGE_H