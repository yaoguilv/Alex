package com.irc.utils;

import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.LogManager;
import org.apache.log4j.Logger;

public class Command_TEST {
	private static Logger LOGGER = LogManager.getLogger(Command_TEST.class);

	public static void main(String[] args) {
		Command command = new Command();
		System.out.println(command.getCommand());
		BasicConfigurator.configure();
		LOGGER.info("yes yes yes log4j print");
	
	}
}

