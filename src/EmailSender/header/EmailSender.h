#ifndef EMAILSENDER_H
#define EMAILSENDER_H
#include <iostream>
#include "Poco/Net/MailMessage.h"
#include "Poco/Net/MailRecipient.h"
#include "Poco/Net/SMTPClientSession.h"
#include "Poco/Net/NetException.h"
#include "Poco/Exception.h"


class EmailSender
{
  public:
  EmailSender(std::string emailAddr)
    {
      this->emailAddr = emailAddr;
    }
    void sendEmail(std::string emailContent, std::string subject);
    inline std::string getEmailAddr() { return emailAddr; }
  private:
    std::string emailAddr;
};
#endif 
