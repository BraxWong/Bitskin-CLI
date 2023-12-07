#include "../header/EmailSender.h"

void EmailSender::sendEmail(std::string emailContent, std::string subject)
{
  Poco::Net::MailMessage mm; 
  mm.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT, "ghostenjob@gmail.com"));
  mm.setSubject(subject);
  mm.setSender(this->emailAddr);
  mm.setContent(emailContent);
  
  Poco::Net::SMTPClientSession* clientSession = new Poco::Net::SMTPClientSession("smtp.gmail.com", 465);
  try
  {
    clientSession->open();
    clientSession->login(Poco::Net::SMTPClientSession::AUTH_LOGIN, "ghostenjob@gmail.com", "Y7877305y!");
    clientSession->sendMessage(mm);
  }
  catch(const Poco::Net::SMTPException& e)
  {
    std::cout << e.message() << "\n";
  }
  catch(const Poco::Net::NetException& netException)
  {
    std::cout << netException.message() << "\n";
  }
  clientSession->close();
  delete clientSession;
}
