package com.badlogic.gdx.imgui;

/**
 * @author octopussy
 */
public class ValueRef<T> {

	private T value;

	public ValueRef(T initial) {
		value = initial;
	}

	public T get() {
		return value;
	}

	public void set(T value) {
		this.value = value;
	}
}
