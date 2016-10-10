file "/Users/juchen3/Jabber/trunk/products/jabber-mac/client/src/mac/app/AriesX/build/Release/Cisco Jabber.app"
#br s -M CHttpSession::OnConnect
#br s -M CHttpSession::ParseReqHeader

br s -M CupSoapClientImpl::WorkThreadCallBackProc
br command add 1
print "CupSoapClientImpl::WorkThreadCallBackProc"
bt
continue
DONE

br s -M CLoginCup::connectOnRetrievedServerInfo
br command add 2
print "CLoginCup::connectOnRetrievedServerInfo"
bt
continue
DONE

run