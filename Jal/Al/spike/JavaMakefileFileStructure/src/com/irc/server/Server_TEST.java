package spike.JavaMakefileFileStructure.src.com.irc.server;

public class Server_TEST {
	public static void main(String[] agrs) {
		ClientRun clientRun = new ClientRun();
		Server server = new Server();

		System.out.println(clientRun.getClientRun());
		System.out.println(server.getServer());
	}
}
