package com.irc.client;

public class Client_TEST {
	public static void main(String[] args) {
		ClientConnection clientConnection = new ClientConnection();
		ClientFenetre clientFenetre = new ClientFenetre();
		Client client = new Client();
		System.out.println(clientConnection.getClientConnection());
		System.out.println(clientFenetre.getClientFenetre());
		System.out.println(client.getClient());
	}
}

