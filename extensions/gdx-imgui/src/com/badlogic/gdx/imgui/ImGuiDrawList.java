package com.badlogic.gdx.imgui;

/**
 * @author mcpussy
 * @date 20/04/2017
 */

/*
struct ImDrawList
{
    // This is what you have to render
    ImVector<ImDrawCmd>     CmdBuffer;          // Commands. Typically 1 command = 1 gpu draw call.
    ImVector<ImDrawIdx>     IdxBuffer;          // Index buffer. Each command consume ImDrawCmd::ElemCount of those
    ImVector<ImDrawVert>    VtxBuffer;          // Vertex buffer.
    ...
}*/

public class ImGuiDrawList {
	public final ImGuiDrawCmd[] cmdBuffer;
	public final int vtxCount;
	public final int vtxElementSize;
	public final int idxCount;
	public final int idxElmentSize;

	public ImGuiDrawList(ImGuiDrawCmd[] cmdBuffer, int vtxCount, int vtxElementSize, int idxCount, int idxElementSize) {
		this.cmdBuffer = cmdBuffer;
		this.vtxCount = vtxCount;
		this.vtxElementSize = vtxElementSize;
		this.idxCount = idxCount;
		this.idxElmentSize = idxElementSize;
	}
}
